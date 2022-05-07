#include "GameEngine.h"

//Constructor for New Game only
GameEngine::GameEngine(Player* player1, Player* player2 ){

    //Created a New Board and a TileBag
    //TileBag includes all the Tiles i.e. 98 Tiles
    tileBag = new TileBag();
    newBoard = new Board();
    bool gameEnd = false;

    //Setting Tiles in Player's Hands (Only for New Game)
    for (int i = 0; i < 7; ++i){
        player1->getPlayerHand()->add_front(tileBag->getTile());
        player2->getPlayerHand()->add_front(tileBag->getTile());
    }

    //In a New game, player 1 has the first chance
    bool playerOneChance = true;
    bool playerTwoChance = false;

    while (gameEnd == false){

        //If tileBag is empty then game ends
        if (tileBag->getTile() == nullptr){
            gameEnd = true;
        }

        //If player hands are empty then game ends
        else if(player1->getPlayerHand()->size() == 0 || player2->getPlayerHand()->size() == 0){
            gameEnd = true;
        }
        
        else{
            //Checking for Turns
            if (playerOneChance == true){
                if(playerPrompt(player1, player2)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = true;
                }
            }
            else{
                if(playerPrompt(player2, player1)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = true;
                    playerTwoChance = false;
                }
            }
        }
    }
    gameEnds(player1, player2);
}

bool GameEngine::playerPrompt(Player* player1, Player* player2){
    std::cout<<"\n"<<player1->getPlayerName()<<", it's your turn"<<std::endl;
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;
    newBoard->printBoard();

    //Displaying Tiles on player's Hand
    std::cout<<"Your hand is"<<std::endl;
    player1->TilesonPlayersHands(player1);

    int placingCounter = 0;
    //User placing tiles with command (loop)
    bool placeDone = false;
    while (placeDone == false){
        std::string input;
        std::cout<<"> ";
        getline(std::cin>>std::ws, input);

        //For place Done
        if (input == "place Done" && placingCounter == 0){
            std::cout<<"You have not placed anything"<<std::endl;
            placeDone = false;
        }

        else if(input == "place Done" && placingCounter > 0){
            placeDone = true;
        }

        //For pass
        //If both users have passed then game ends
        //It is 3 because the player who passed first will be asked one more time
        else if(input == "pass"){
            if (placingCounter > 0){
                player1->setPassCounter(0);
                std::cout<<"Use place Done instead because you have already placed a tile"<<std::endl;
                placeDone = false;
            }
            else{
                placeDone = true;
                player1->setPassCounter(player1->getPassCounter()+1);

                if (player1->getPassCounter() >= 2){
                    //Game Ends
                    return true;
                }
            }
        }

        //For Replacing
        else if ((input.substr(0, 7) == "replace") && checksLetterinHand(input[8], player1->getPlayerHand())){
            
            //If Player replaces tile then also its previous Pass counter will become useless
            player1->setPassCounter(0);

            //Tile to Remove
            Tile* tileToRemove = getTileFromHand(input[8], player1);

            //setting tiles on hand again
            player1->getPlayerHand()->add_back(tileBag->getTile());

            //adds the tile from players hand to the tile bag
            tileBag->addTile(tileToRemove);
            placeDone = true;
        }

        //For Placing
        //Checks if the input tile is in players hand or not
        else if (checkInputforPlacing(input, player1->getPlayerHand())){
            //If the Player places Tiles, then its Pass counter will become 0 again
            player1->setPassCounter(0);
            ++placingCounter;

            Tile* tileToPlace = getTileFromHand(input[6], player1);

            //Setting rows, cols for positioning the Tile
            int col = convertChartoInt(input[11]);
            int row;
            if (input.size() == 14){
                row = ((int)input[12] - 48)*10 + (int)input[13]-48;
            }
            else{
                row = (int)input[12] - 48;
            }
            
            //Placing Tile on Board
            newBoard->updateBoard(tileToPlace, row, col);

            //Getting Tile Value
            int tileScore = tileToPlace->getValue();

            //Player's Score update
            player1->setPlayerScore(player1->getPlayerScore() + tileScore);

            //Draw a Replacement Tile from Tile bag and add it to the Player's hand, if there are available tiles
            player1->getPlayerHand()->add_back(tileBag->getTile());
        }
        
        else if(!checksLetterinHand(input[6], player1->getPlayerHand())){
            std::cout<<"Tile is not in Hand"<<std::endl;
        }

        else{
            std::cout<<"Invalid Input"<<std::endl;
        }
    }
    return false;
}

Tile* GameEngine::getTileFromHand(char tileLetter, Player* player1){
    Tile* tileToPlace = new Tile('!', -1);

    //Getting Tile for that particular letter
    for (int i = 0; i < 7; ++i){
        if (tileLetter == player1->getPlayerHand()->get(i)->getLetter()){

            //Sets the tile from hand to tileToPlace
            tileToPlace->setLetter(player1->getPlayerHand()->get(i)->getLetter());
            tileToPlace->setValue(player1->getPlayerHand()->get(i)->getValue());
            
            //And deletes the tile too
            player1->getPlayerHand()->remove(i);
            return tileToPlace;
        }
    }
    return tileToPlace;
}


//Displays the Ending Messages
void GameEngine::gameEnds(Player* player1, Player* player2){
    std::cout<<"\nGame Over"<<std::endl;
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;

    int playerOneScore = player1->getPlayerScore();
    int playerTwoScore = player2->getPlayerScore();

    if (playerOneScore > playerTwoScore){
        std::cout<<"Player "<<player1->getPlayerName()<< " won!"<<std::endl;
    }
    else{
        std::cout<<"Player "<<player2->getPlayerName()<< " won!"<<std::endl;
    }

    std::cout<<"Goodbye 😄"<<std::endl;
}


//Validates Input in 3 ways: Placed Tile should be in Hands, Command should be correctly formatted,
//Coordinates given should legal
bool GameEngine::checkInputforPlacing(std::string input, LinkedList* hand){
    if(checkBoardCoordinates(input) && checksLetterinHand(input[6], hand) && checksString(input)){
        return true;
    }
    return false;
}


//Checks if Row entered is Correct
bool GameEngine::checkRow(std::string input){
    int row;
    if (input.size() == 14){
        row = ((int)input[12] - 48)*10 + (int)input[13]-48;
    }
    else{
        row = (int)input[12] - 48;
    }
    for (int i = 0; i < 15; ++i){
        if (row == i){
            return true;
        }
    }
    return false;
}


//Checks if Column entered is Correct
bool GameEngine::checkCol(char col){
    for (char i = 'A'; i < 'O'; ++i){
        if (col == i){
            return true;
        }
    }
    return false;
}


//Check Board Coordinated (Rows, Cols)
bool GameEngine::checkBoardCoordinates(std::string input){

    if(checkRow(input) && checkCol(input[11])){
        return true;
    }
    return false;
}


//Checks String entered is correct
bool GameEngine::checksString(std::string input){
    if ((input.substr(0,5).compare("place") == 0) && (input.substr(8,2).compare("at") == 0)){
        return true;
    }
    return false;
}


//Checks Letter is present in Hand or not
bool GameEngine::checksLetterinHand(char c, LinkedList* hand){
    for (int i = 0; i < 7; ++i){
        if (c == hand->get(i)->getLetter()){
            return true;
        }
    }
    return false;
}


//Convert character to integer value
int GameEngine::convertChartoInt(char c){
    int j=0;
    for (char i = 'A'; i <= c; i++){
        ++j;
    }
    return j;
}


