#include "GameEngine.h"
// #include "Board.h"
// #include "TileBag.h"
// #include <istream>


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
                std::cout<<"\n\nNEW PLAYER\n\n"<<std::endl;
                playerPrompt(player1, player2);
                playerOneChance = false;
                playerTwoChance = true;
            }
            else{
                std::cout<<"\n\nNEW PLAYER\n\n"<<std::endl;
                playerPrompt(player2, player1); 
                playerOneChance = true;
                playerTwoChance = false;
            }
        }
    }
    gameEnds(player1, player2);
}

void GameEngine::playerPrompt(Player* player1, Player* player2){
    std::cout<<player1->getPlayerName()<<", it's your turn"<<std::endl;
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;
    newBoard->printBoard();

    //Displaying Tiles on player's Hand
    std::cout<<"Your hand is"<<std::endl;
    player1->TilesonPlayersHands(player1);

    //User placing tiles with command loop
    bool placeDone = false;
    while (placeDone == false){
        std::string input;
        std::cout<<"> ";
        getline(std::cin>>std::ws, input);

        //For place Done
        if (input == "place Done"){
            placeDone = true;
        }

        //For pass
        else if(input == "pass"){
            placeDone = true;
        }

        //For Replacing
        else if ((input.substr(0, 7) == "replace") && checksLetterinHand(input[8], player1->getPlayerHand())){
            std::cout<<"replace"<<std::endl;
        }

        //For Placing
        //Checks if the input tile is in players hand or not
        else if (checkInputforPlacing(input, player1->getPlayerHand())){

            //Getting Tile for that particular letter
            Letter tileLetter = input[6];
            int index = convertChartoInt(tileLetter);
            Tile* tileToPlace = player1->getPlayerHand()->get(index);

            //Setting rows, cols for positioning the Tile
            int col = convertChartoInt(input[11]);
            int row = input[12];

            // Location* location = new Location(row, col);

            //Placing Tile on Board
            player1->placesTile(tileToPlace, row, col);
        }
        else{
            std::cout<<"Invalid input"<<std::endl;
        }
    }
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

//Validates Input
bool GameEngine::checkInputforPlacing(std::string input, LinkedList* hand){

    if(checkBoardCoordinates(input) && checksLetterinHand(input[6], hand) && checksString(input)){
        return true;
    }
    std::cout<<"Input Error 130"<<std::endl;
    return false;
}


//Checks if Row entered is Correct
bool GameEngine::checkRow(std::string input){
    int a = (int)input[12] - 48;
    for (int i = 0; i < 15; ++i){
        if (a == i){
            return true;
        }
    }
    std::cout<<"Input Error 142"<<std::endl;
    return false;
}


//Checks if Column entered is Correct
bool GameEngine::checkCol(char col){
    for (char i = 'A'; i < 'O'; ++i){
        if (col == i){
            return true;
        }
    }
    std::cout<<"Input Error 154"<<std::endl;
    return false;
}


//Check Board Coordinated (Rows, Cols)
bool GameEngine::checkBoardCoordinates(std::string input){

    if(checkRow(input) && checkCol(input[11])){
        return true;
    }
    std::cout<<"Input Error 164"<<std::endl;
    return false;
}


//Checks String entered is correct
bool GameEngine::checksString(std::string input){
    if ((input.substr(0,5).compare("place") == 0) && (input.substr(8,2).compare("at") == 0)){
        return true;
    }
    std::cout<<"Input Error 174"<<std::endl;
    return false;
}


//Checks Letter is present in Hand or not
bool GameEngine::checksLetterinHand(char c, LinkedList* hand){
    for (int i = 0; i < 7; ++i){
        if (c == hand->get(i)->getLetter()){
            return true;
        }
    }
    std::cout<<"Input Error"<<std::endl;
    return false;
}

//Convert character to integer value
int GameEngine::convertChartoInt(char c){
    int i=0;
    for (char i = 'A'; i <= c; i++){
        ++i;
    }
    return i;
}


