#include "GameEngine.h"
#include <fstream>
#include <sstream>

/* Default Constructor */
GameEngine::GameEngine(){}

GameEngine::GameEngine(bool enableEnhancement){
    this-> enableEnhancement = enableEnhancement;
}

/* De-constructor */
GameEngine::~GameEngine() {}

/* Constructor for New Game */
GameEngine::GameEngine(Player* player1, Player* player2, bool enableEnhancement){
    this-> player1 = player1;
    this-> player2 = player2;    
    this-> enableEnhancement = enableEnhancement;
}

/* Constructor for New Game */
GameEngine::GameEngine(Player* player1, Player* player2, Player* player3, Player* player4, bool enableEnhancement){
    this-> player1 = player1;
    this-> player2 = player2;
    this-> player3 = player3;
    this-> player4 = player4;        
    this-> enableEnhancement = enableEnhancement;
}

/* Loads the saved games */
void GameEngine::loadGame(std::string savedData[]){
    // Setting player 1 Data
    int score1 = std::stoi(savedData[1]);
    LinkedList* hand1 = new LinkedList();

    // Variables used for iteration to read players hand from saved file
    int letter_counter = -5;
    int value_counter = -3;

    // Reading players Hand and setting values
    for (int i = 0; i < 7; ++i){
        char ch = savedData[2].substr(letter_counter+5, 1).at(0);
        letter_counter = letter_counter + 5;

        int value = std::stoi(savedData[2].substr(value_counter+5, 1));
        value_counter = value_counter + 5;

        Tile* tile = new Tile(ch, value);
        hand1->add_back(tile);
    }
    
    // Creating player 1
    Player* player1 = new Player(savedData[0], 1, score1, hand1);

    // Setting player 2 Data
    int score2 = std::stoi(savedData[4]);
    LinkedList* hand2 = new LinkedList();
    letter_counter = -5;
    value_counter = -3;

    // Reading players Hand and setting values
    for (int i = 0; i < 7; ++i){
        char ch = savedData[5].substr(letter_counter+5, 1).at(0);
        letter_counter = letter_counter + 5;

        int value = std::stoi(savedData[5].substr(value_counter+5, 1));
        value_counter = value_counter + 5;

        Tile* tile = new Tile(ch, value);
        hand2->add_back(tile);
    }

    // Creating Player 2
    Player* player2 = new Player(savedData[3], 1, score2, hand2);

    // Creating an empty Tile Bag
    tileBag = new TileBag();
    tileBag->clear();
    std::string str;
    std::istringstream iss(savedData[7]);

    // Adding tiles to Tile Bag from saved file
    while (std::getline(iss, str, ',')){
        Tile* tile2 = new Tile(str[0], str[2]);
        tileBag->addTile(tile2);
    }

    // Creating a New Board
    newBoard = new Board();
    std::istringstream iss2(savedData[6]);

    // Adding already placed tiles to Board
    while (std::getline(iss2, str, ',')){
        Tile* tile3 = new Tile(str[0], 0);
        if (str.size() == 5){
            int row = ((int)str[3]-48)*10 + (int)str[4]-48;
            newBoard->updateBoard(tile3, row, convertChartoInt(str[2]));
        }
        else{
            newBoard->updateBoard(tile3, (int)str[3]-48, convertChartoInt(str[2]));
        }
    }

    playerOneChance = true;
    playerTwoChance = false;

    while (gameEnd == false){

        // If tileBag is empty then game ends
        if (tileBag->getTile() == nullptr){
            gameEnd = true;
        }

        // If player hands are empty then game ends
        else if(player1->getPlayerHand()->size() == 0 || player2->getPlayerHand()->size() == 0){
            gameEnd = true;
        }
        
        else{
            // Checking for Turns
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

/* Starts the Game */
void GameEngine::gameStarts(){
    // Created a New Board and a TileBag
    // TileBag includes all the Tiles i.e. 98 Tiles
    tileBag = new TileBag();
    newBoard = new Board();
    gameEnd = false;

    // Setting Tiles in Both Player's Hands (Only for New Game)
    for (int i = 0; i < 7; ++i){
        player1->getPlayerHand()->add_front(tileBag->getTile());
        player2->getPlayerHand()->add_front(tileBag->getTile());
    }

    // In a New game, player 1 has the first chance
    playerOneChance = true;
    playerTwoChance = false;

    // Loop for playing Game
    while (gameEnd == false){

        // If tileBag is empty then game ends
        if (tileBag->getTile() == nullptr){
            gameEnd = true;
        }

        // If player hands are empty then game ends
        else if(player1->getPlayerHand()->size() == 0 || player2->getPlayerHand()->size() == 0){
            gameEnd = true;
        }
       
        else{
            // Checking for Turns
            // When its Player one's chance
            if (playerOneChance == true){
                if(playerPrompt(player1, player2)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = true;
                    if (enableEnhancement == true){
                        playerThreeChance = false;
                        playerFourChance = false;
                    }
                }
            }
            // When its Player two's chance
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
    if (gameSave == true){
        gameSaves();
    }
    else if(gameQuit == true){
        gameQuits();
    }
    else{
        gameEnds(player1, player2);
    }
}

/* Loads the saved games */
void GameEngine::loadGameEnhancement(std::string savedData[]){
    // Setting player 1 Data
    int score1 = std::stoi(savedData[1]);
    LinkedList* hand1 = new LinkedList();

    // Variables used for iteration to read players hand from saved file
    int letter_counter = -5;
    int value_counter = -3;

    // Reading players Hand and setting values
    for (int i = 0; i < 7; ++i){
        char ch = savedData[2].substr(letter_counter+5, 1).at(0);
        letter_counter = letter_counter + 5;

        int value = std::stoi(savedData[2].substr(value_counter+5, 1));
        value_counter = value_counter + 5;

        Tile* tile = new Tile(ch, value);
        hand1->add_back(tile);
    }
    
    // Creating player 1
    Player* player1 = new Player(savedData[0], 1, score1, hand1);

    // Setting player 2 Data
    int score2 = std::stoi(savedData[4]);
    LinkedList* hand2 = new LinkedList();
    letter_counter = -5;
    value_counter = -3;

    // Reading players Hand and setting values
    for (int i = 0; i < 7; ++i){
        char ch = savedData[5].substr(letter_counter+5, 1).at(0);
        letter_counter = letter_counter + 5;

        int value = std::stoi(savedData[5].substr(value_counter+5, 1));
        value_counter = value_counter + 5;

        Tile* tile = new Tile(ch, value);
        hand2->add_back(tile);
    }

    // Creating Player 2
    Player* player2 = new Player(savedData[3], 2, score2, hand2);

    // Setting player 3 Data
    int score3 = std::stoi(savedData[7]);
    LinkedList* hand3 = new LinkedList();

    // Variables used for iteration to read players hand from saved file
    letter_counter = -5;
    value_counter = -3;

    // Reading players Hand and setting values
    for (int i = 0; i < 7; ++i){
        char ch = savedData[8].substr(letter_counter+5, 1).at(0);
        letter_counter = letter_counter + 5;

        int value = std::stoi(savedData[8].substr(value_counter+5, 1));
        value_counter = value_counter + 5;

        Tile* tile = new Tile(ch, value);
        hand3->add_back(tile);
    }
    
    // Creating player 3
    Player* player3 = new Player(savedData[6], 3, score3, hand3);

    // Setting player 4 Data
    int score4 = std::stoi(savedData[10]);
    LinkedList* hand4 = new LinkedList();

    // Variables used for iteration to read players hand from saved file
    letter_counter = -5;
    value_counter = -3;

    // Reading players Hand and setting values
    for (int i = 0; i < 7; ++i){
        char ch = savedData[11].substr(letter_counter+5, 1).at(0);
        letter_counter = letter_counter + 5;

        int value = std::stoi(savedData[11].substr(value_counter+5, 1));
        value_counter = value_counter + 5;

        Tile* tile = new Tile(ch, value);
        hand4->add_back(tile);
    }
    
    // Creating player 4
    Player* player4 = new Player(savedData[9], 4, score4, hand4);

    // Creating an empty Tile Bag
    tileBag = new TileBag();
    tileBag->clear();
    std::string str;
    std::istringstream iss(savedData[13]);

    // Adding tiles to Tile Bag from saved file
    while (std::getline(iss, str, ',')){
        Tile* tile2 = new Tile(str[0], str[2]);
        tileBag->addTile(tile2);
    }

    // Creating a New Board
    newBoard = new Board();
    std::istringstream iss2(savedData[12]);

    // Adding already placed tiles to Board
    while (std::getline(iss2, str, ',')){
        Tile* tile3 = new Tile(str[0], 0);
        if (str.size() == 5){
            int row = ((int)str[3]-48)*10 + (int)str[4]-48;
            newBoard->updateBoard(tile3, row, convertChartoInt(str[2]));
        }
        else{
            newBoard->updateBoard(tile3, (int)str[3]-48, convertChartoInt(str[2]));
        }
    }

    playerOneChance = true;
    playerTwoChance = false;
    playerThreeChance = false;
    playerFourChance = false;

    while (gameEnd == false){

        // If tileBag is empty then game ends
        if (tileBag->getTile() == nullptr){
            gameEnd = true;
        }

        // If player hands are empty then game ends
        else if(player1->getPlayerHand()->size() == 0 || player2->getPlayerHand()->size() == 0 || player3->getPlayerHand()->size() == 0 || player4->getPlayerHand()->size() == 0){
            gameEnd = true;
        }
        
        else{
            // Checking for Turns
            // When its Player one's chance
            if (playerOneChance == true){
                if(playerPrompt(player1, player2, player3, player4)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = true;
                    if (enableEnhancement == true){
                        playerThreeChance = false;
                        playerFourChance = false;
                    }
                }
            }
            // When its Player two's chance
            else if (playerTwoChance == true){
                if(playerPrompt(player3, player1, player2, player4)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = false;
                    if (enableEnhancement == true){
                        playerThreeChance = true;
                        playerFourChance = false;
                    }
                }
            } 
            else if (playerThreeChance == true){
                if(playerPrompt(player4, player1, player2, player3)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = false;
                    if (enableEnhancement == true){
                        playerThreeChance = false;
                        playerFourChance = true;
                    }
                }
            }
            else{
                if(playerPrompt(player2, player1, player3, player4)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = true;
                    playerTwoChance = false;
                     if (enableEnhancement == true){
                        playerThreeChance = false;
                        playerFourChance = false;
                    }
                }
            }
        }
    }
    gameEnds(player1, player2, player3, player4);
}

/* Starts the Game */
void GameEngine::gameStartsEnhancement(){
    // Created a New Board and a TileBag
    // TileBag includes all the Tiles i.e. 98 Tiles
    tileBag = new TileBag();
    newBoard = new Board();
    gameEnd = false;

    // Setting Tiles in Both Player's Hands (Only for New Game)
    for (int i = 0; i < 7; ++i){
        player1->getPlayerHand()->add_front(tileBag->getTile());
        player2->getPlayerHand()->add_front(tileBag->getTile());
        player3->getPlayerHand()->add_front(tileBag->getTile());
        player4->getPlayerHand()->add_front(tileBag->getTile());


    }

    // In a New game, player 1 has the first chance
    playerOneChance = true;
    playerTwoChance = false;
    if (enableEnhancement == true){
        playerThreeChance = false;
        playerFourChance = false;
    }

    // Loop for playing Game
    while (gameEnd == false){

        // If tileBag is empty then game ends
        if (tileBag->getTile() == nullptr){
            gameEnd = true;
        }

        // If player hands are empty then game ends
        else if(player1->getPlayerHand()->size() == 0 || player2->getPlayerHand()->size() == 0 || player3->getPlayerHand()->size() == 0 || player4->getPlayerHand()->size() == 0){
            gameEnd = true;
        }       
        else{
            // Checking for Turns
            // When its Player one's chance
            if (playerOneChance == true){
                if(playerPrompt(player1, player2, player3, player4)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = true;
                    playerThreeChance = false;
                    playerFourChance = false;
                }
            }
            // When its Player two's chance
            else if (playerTwoChance == true){
                if(playerPrompt(player2, player1, player3, player4)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = false;
                    playerThreeChance = true;
                    playerFourChance = false;
                }
            } 
            else if (playerThreeChance == true){
                if(playerPrompt(player3, player1, player2, player4)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = false;
                    playerTwoChance = false;
                    playerThreeChance = false;
                    playerFourChance = true;
                }
            }
            else{
                if(playerPrompt(player4, player1, player2, player3)){
                    gameEnd = true;
                }
                else{
                    playerOneChance = true;
                    playerTwoChance = false;
                    playerThreeChance = false;
                    playerFourChance = false;
                }
            }
        }
    }
    if (gameSave == true){
        gameSaves();
    }
    else if(gameQuit == true){
        gameQuits();
    }
    else{
        gameEnds(player1, player2);
    }
}

// When players quits the game
void GameEngine::gameQuits(){
    std::cout<<"Goodbye"<<std::endl;
}

// When players saves the game
void GameEngine::gameSaves(){
    std::cout<<"Game Saved\nGoodbye"<<std::endl;
}

/* Commands for Players: Place Tile, Save, Pass, Replace & Quit */
bool GameEngine::playerPrompt(Player* player1, Player* player2){
    errorMsg = false;
    // Displays whose turn is now
    std::cout<<"\n"<<player1->getPlayerName()<<", it's your turn"<<std::endl;

    // Displays the Score for each user
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;

    // Prints the updated Board
    newBoard->printBoard();

    // Displaying Tiles on player's Hand
    std::cout<<"Your hand is"<<std::endl;
    player1->TilesonPlayersHands(player1);

    int placingCounter = 0;
    bool placeDone = false;

    // Loop for player placing tile until placing is Done
    while (placeDone == false){
        errorMsg = false;
        // Takes the Input from User
        std::string input;
        std::cout<<"> ";
        getline(std::cin>>std::ws, input);

        // For place Done
        // If player has not placed anything and used place Done command then it will show a warning
        if (input == "place Done" && placingCounter == 0){
            std::cout<<"You have not placed anything"<<std::endl;
            placeDone = false;
        }

        // Checks for the input
        else if(input == "place Done" && placingCounter > 0){
            placeDone = true;
        }

        // Validates save input
        else if(input.substr(0,4) == "save"){

            // stores file name where the game is going to be saved
            std::string output = input.substr(5,input.size()-4);

            // Checks if file exists or not
            if(checkFileExists(output)){

                // Buffer initialised to write in the file
                std::ofstream file(output);
                // Writes Player one's Name
                file << player1->getPlayerName() << std::endl;
                // Writes Player one's Score
                file << player1->getPlayerScore() << std::endl;
                // Writes Player one's Hand
                file << player1->getPlayerHand()->get(0)->getLetter()<<"-"<<player1->getPlayerHand()->get(0)->getValue();
                for (int i = 1; i < player1->getPlayerHand()->size(); ++i){
                    file << ", "<< player1->getPlayerHand()->get(i)->getLetter()<<"-"<<player1->getPlayerHand()->get(i)->getValue();
                }
                file << std::endl;

                // Writes Player two's Name
                file << player2->getPlayerName() << std::endl;
                // Write Player two's Score
                file << player2->getPlayerScore() << std::endl;
                // Write player two's Hand
                file << player2->getPlayerHand()->get(0)->getLetter()<<"-"<<player2->getPlayerHand()->get(0)->getValue();
                for (int i = 1; i < player2->getPlayerHand()->size(); ++i){
                    file << ", "<< player2->getPlayerHand()->get(i)->getLetter()<<"-"<<player2->getPlayerHand()->get(i)->getValue();
                }
                file << std::endl;

                // Write tiles placed on Board to file
                for (int i = 0; i < ENV_DIM; ++i){
                    for (int j = 0; j < ENV_DIM; ++j){
                        if (newBoard->board[i][j] != nullptr){
                            char ch = static_cast<char>(i+65);
                            file << newBoard->board[i][j]->getLetter() << "@" << ch << j << ",";
                        }
                    }
                }
                file << "" << std::endl;

                // Writes Tiles left in Tile Bag to file
                file << tileBag->get(0)->getLetter() << "-" << tileBag->get(0)->getValue() << std::flush;
                for (int i = 1; i < tileBag->size; ++i){
                    file << "," << tileBag->get(i)->getLetter() << "-" << tileBag->get(i)->getValue() << std::flush;
                }
                file.flush();
                file << "" << std::endl;

                // Writes Player's name whose chance is going on
                file << player1->getPlayerName() << std::endl;
                
                // Game Ends
                gameSave = true;
                return true;
            }
        } 

        else if(input == "quit" || std::cin.eof()){
            gameQuit = true;
            return true;
        }

        // For pass
        // If both users have passed then game ends
        // It is 3 because the player who passed first will be asked one more time
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
                    // Game Ends
                    return true;
                }
            }
        }

        // For Replacing
        else if ((input.substr(0, 7) == "replace") && checksLetterinHand(input[8], player1->getPlayerHand())){
            
            // If Player replaces tile then also its previous Pass counter will become useless
            player1->setPassCounter(0);

            // Tile to Remove
            Tile* tileToRemove = getTileFromHand(input[8], player1);

            // setting tiles on hand again
            player1->getPlayerHand()->add_back(tileBag->getTile());

            // adds the tile from players hand to the tile bag
            tileBag->addTile(tileToRemove);
            placeDone = true;
        }

        // For Placing
        // Checks if the input tile is in players hand or not
        else if (checkInputforPlacing(input, player1->getPlayerHand())){

            // If the Player places Tiles, then its Pass counter will become 0 again
            player1->setPassCounter(0);
            ++placingCounter;

            Tile* tileToPlace = getTileFromHand(input[6], player1);

            // Setting rows, cols for positioning the Tile
            int col = convertChartoInt(input[11]);
            int row;
            if (input.size() == 14){
                row = ((int)input[12] - 48)*10 + (int)input[13]-48;
            }
            else{
                row = (int)input[12] - 48;
            }
            
            // Placing Tile on Board
            newBoard->updateBoard(tileToPlace, row, col);

            // Getting Tile Value
            int tileScore = tileToPlace->getValue();

            // Player's Score update
            player1->setPlayerScore(player1->getPlayerScore() + tileScore);

            // Draw a Replacement Tile from Tile bag and add it to the Player's hand, if there are available tiles
            player1->getPlayerHand()->add_back(tileBag->getTile());

            // If all tiles placed, then BINGO!!!
            if (placingCounter == 7){
                std::cout<<""<<std::endl;
                std::cout<<"BINGO!!!\n"<<std::endl;
                player1->setPlayerScore(player1->getPlayerScore() + 50);
                placeDone = true;
            }
        } else if (enableEnhancement == true && input == "help") {

            // Help For Place Tile
            std::cout << "◉ To Place a Tile Use Command: \"place TileLetter at CoordinatesFromTheBoard\"" << 
            " eg. place A at C2, NOTE: commands are case sensitive, they should be written exactly as shown! " << std::endl;

            // Help For Save Game
            std::cout << "◉ To Save Game Use Command: \"save FileName.txt\" eg. save game1.txt," << 
            " NOTE: All lowercase characters and always include .txt" << std::endl;

            // Help for Completing Turn
            std::cout << "◉ To Complete Your Turn Use Command: \"place Done\"" << 
            " NOTE: The command should be exactly as shown" << std::endl;

            // Help For Passing
            std::cout << "◉ To Pass Your Turn Use Command: \"pass\"" << 
            " NOTE: The command should be exactly as shown" << std::endl;

            // Help For Replacing Tiles
            std::cout << "◉ To Replace a Tile Use Command: \"replace TileLetterFromHand\" eg. replace A" << 
            " NOTE: The Tile You Are Replacing Must Be in Hand" << std::endl;

            // Help For Quiting Game
            std::cout << "◉ To Quit Game Use Command: \"quit\" or finish the game to end" << 
            " NOTE: The command should be exactly as shown" << std::endl;

            std::cout << "" << std::endl;

        }

        else{
            if (enableEnhancement == true){
                std::cout<<"Invalid Input"<<std::endl;
                if(errorMsg == false) {    
                    std::cout<<"Input does not match the Required Commands! Please type command \"help\" to see all available commands!"<<std::endl;
                }
            } else {
                std::cout<<"Invalid Input"<<std::endl;
            }
            
        }
    }
    return false;
}

bool GameEngine::playerPrompt(Player* player1, Player* player2, Player* player3, Player* player4){
    errorMsg = false;
    // Displays whose turn is now
    std::cout<<"\n"<<player1->getPlayerName()<<", it's your turn"<<std::endl;

    // Displays the Score for each user
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player3->getPlayerName()<<": "<<player3->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player4->getPlayerName()<<": "<<player4->getPlayerScore()<<std::endl;


    // Prints the updated Board
    newBoard->printBoard();

    // Displaying Tiles on player's Hand
    std::cout<<"Your hand is"<<std::endl;
    player1->TilesonPlayersHands(player1);

    int placingCounter = 0;
    bool placeDone = false;

    // Loop for player placing tile until placing is Done
    while (placeDone == false){
        errorMsg = false;
        // Takes the Input from User
        std::string input;
        std::cout<<"> ";
        getline(std::cin>>std::ws, input);

        // For place Done
        // If player has not placed anything and used place Done command then it will show a warning
        if (input == "place Done" && placingCounter == 0){
            std::cout<<"You have not placed anything"<<std::endl;
            placeDone = false;
        }

        // Checks for the input
        else if(input == "place Done" && placingCounter > 0){
            placeDone = true;
        }

        // Validates save input
        else if(input.substr(0,4) == "save"){

            // stores file name where the game is going to be saved
            std::string output = input.substr(5,input.size()-4);

            // Checks if file exists or not
            if(checkFileExists(output)){

                // Buffer initialised to write in the file
                std::ofstream file(output);
                // Writes Player one's Name
                file << player1->getPlayerName() << std::endl;
                // Writes Player one's Score
                file << player1->getPlayerScore() << std::endl;
                // Writes Player one's Hand
                file << player1->getPlayerHand()->get(0)->getLetter()<<"-"<<player1->getPlayerHand()->get(0)->getValue();
                for (int i = 1; i < player1->getPlayerHand()->size(); ++i){
                    file << ", "<< player1->getPlayerHand()->get(i)->getLetter()<<"-"<<player1->getPlayerHand()->get(i)->getValue();
                }
                file << std::endl;

                // Writes Player two's Name
                file << player2->getPlayerName() << std::endl;
                // Write Player two's Score
                file << player2->getPlayerScore() << std::endl;
                // Write player two's Hand
                file << player2->getPlayerHand()->get(0)->getLetter()<<"-"<<player2->getPlayerHand()->get(0)->getValue();
                for (int i = 1; i < player2->getPlayerHand()->size(); ++i){
                    file << ", "<< player2->getPlayerHand()->get(i)->getLetter()<<"-"<<player2->getPlayerHand()->get(i)->getValue();
                }
                file << std::endl;

                // Writes Player three's Name
                file << player3->getPlayerName() << std::endl;
                // Write Player three's Score
                file << player3->getPlayerScore() << std::endl;
                // Write player three's Hand
                file << player3->getPlayerHand()->get(0)->getLetter()<<"-"<<player3->getPlayerHand()->get(0)->getValue();
                for (int i = 1; i < player3->getPlayerHand()->size(); ++i){
                    file << ", "<< player3->getPlayerHand()->get(i)->getLetter()<<"-"<<player3->getPlayerHand()->get(i)->getValue();
                }
                file << std::endl;

                // Writes Player four's Name
                file << player4->getPlayerName() << std::endl;
                // Write Player four's Score
                file << player4->getPlayerScore() << std::endl;
                // Write player four's Hand
                file << player4->getPlayerHand()->get(0)->getLetter()<<"-"<<player4->getPlayerHand()->get(0)->getValue();
                for (int i = 1; i < player4->getPlayerHand()->size(); ++i){
                    file << ", "<< player4->getPlayerHand()->get(i)->getLetter()<<"-"<<player4->getPlayerHand()->get(i)->getValue();
                }
                file << std::endl;

                // Write tiles placed on Board to file
                for (int i = 0; i < ENV_DIM; ++i){
                    for (int j = 0; j < ENV_DIM; ++j){
                        if (newBoard->board[i][j] != nullptr){
                            char ch = static_cast<char>(i+65);
                            file << newBoard->board[i][j]->getLetter() << "@" << ch << j << ",";
                        }
                    }
                }
                file << "" << std::endl;

                // Writes Tiles left in Tile Bag to file
                file << tileBag->get(0)->getLetter() << "-" << tileBag->get(0)->getValue() << std::flush;
                for (int i = 1; i < tileBag->size; ++i){
                    file << "," << tileBag->get(i)->getLetter() << "-" << tileBag->get(i)->getValue() << std::flush;
                }
                file.flush();
                file << "" << std::endl;

                // Writes Player's name whose chance is going on
                file << player1->getPlayerName() << std::endl;
                
                // Game Ends
                gameSave = true;
                return true;
            }
        } 

        else if(input == "quit" || std::cin.eof()){
            gameQuit = true;
            return true;
        }

        // For pass
        // If both users have passed then game ends
        // It is 3 because the player who passed first will be asked one more time
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
                    // Game Ends
                    return true;
                }
            }
        }

        // For Replacing
        else if ((input.substr(0, 7) == "replace") && checksLetterinHand(input[8], player1->getPlayerHand())){
            
            // If Player replaces tile then also its previous Pass counter will become useless
            player1->setPassCounter(0);

            // Tile to Remove
            Tile* tileToRemove = getTileFromHand(input[8], player1);

            // setting tiles on hand again
            player1->getPlayerHand()->add_back(tileBag->getTile());

            // adds the tile from players hand to the tile bag
            tileBag->addTile(tileToRemove);
            placeDone = true;
        }

        // For Placing
        // Checks if the input tile is in players hand or not
        else if (checkInputforPlacing(input, player1->getPlayerHand())){

            // If the Player places Tiles, then its Pass counter will become 0 again
            player1->setPassCounter(0);
            ++placingCounter;

            Tile* tileToPlace = getTileFromHand(input[6], player1);

            // Setting rows, cols for positioning the Tile
            int col = convertChartoInt(input[11]);
            int row;
            if (input.size() == 14){
                row = ((int)input[12] - 48)*10 + (int)input[13]-48;
            }
            else{
                row = (int)input[12] - 48;
            }
            
            // Placing Tile on Board
            newBoard->updateBoard(tileToPlace, row, col);

            // Getting Tile Value
            int tileScore = tileToPlace->getValue();

            // Player's Score update
            player1->setPlayerScore(player1->getPlayerScore() + tileScore);

            // Draw a Replacement Tile from Tile bag and add it to the Player's hand, if there are available tiles
            player1->getPlayerHand()->add_back(tileBag->getTile());

            // If all tiles placed, then BINGO!!!
            if (placingCounter == 7){
                std::cout<<""<<std::endl;
                std::cout<<"BINGO!!!\n"<<std::endl;
                player1->setPlayerScore(player1->getPlayerScore() + 50);
                placeDone = true;
            }
        } else if (enableEnhancement == true && input == "help") {

            // Help For Place Tile
            std::cout << "◉ To Place a Tile Use Command: \"place TileLetter at CoordinatesFromTheBoard\"" << 
            " eg. place A at C2, NOTE: commands are case sensitive, they should be written exactly as shown! " << std::endl;

            // Help For Save Game
            std::cout << "◉ To Save Game Use Command: \"save FileName.txt\" eg. save game1.txt," << 
            " NOTE: All lowercase characters and always include .txt" << std::endl;

            // Help for Completing Turn
            std::cout << "◉ To Complete Your Turn Use Command: \"place Done\"" << 
            " NOTE: The command should be exactly as shown" << std::endl;

            // Help For Passing
            std::cout << "◉ To Pass Your Turn Use Command: \"pass\"" << 
            " NOTE: The command should be exactly as shown" << std::endl;

            // Help For Replacing Tiles
            std::cout << "◉ To Replace a Tile Use Command: \"replace TileLetterFromHand\" eg. replace A" << 
            " NOTE: The Tile You Are Replacing Must Be in Hand" << std::endl;

            // Help For Quiting Game
            std::cout << "◉ To Quit Game Use Command: \"quit\" or finish the game to end" << 
            " NOTE: The command should be exactly as shown" << std::endl;

            std::cout << "" << std::endl;

        }

        else{
            if (enableEnhancement == true){
                std::cout<<"Invalid Input"<<std::endl;
                if(errorMsg == false) {    
                    std::cout<<"Input does not match the Required Commands! Please type command \"help\" to see all available commands!"<<std::endl;
                }
            } else {
                std::cout<<"Invalid Input"<<std::endl;
            }
            
        }
    }
    return false;
}

/* Checks if user input file exists to load */
bool GameEngine::checkFileExists(std::string output){
    std::cout<<"File Name: "<<output<<std::endl;
    std::ofstream file(output);

    if (!file.fail()){
        return true;
    }
    return false;
}


/* Gets tiles from Players Hand */ 
Tile* GameEngine::getTileFromHand(char tileLetter, Player* player1){
    Tile* tileToPlace = new Tile('!', -1);

    // Getting Tile for that particular letter
    for (int i = 0; i < 7; ++i){
        if (tileLetter == player1->getPlayerHand()->get(i)->getLetter()){

            // Sets the tile from hand to tileToPlace
            tileToPlace->setLetter(player1->getPlayerHand()->get(i)->getLetter());
            tileToPlace->setValue(player1->getPlayerHand()->get(i)->getValue());
            
            // And deletes the tile too
            player1->getPlayerHand()->remove(i);
            return tileToPlace;
        }
    }
    return tileToPlace;
}

/* Displays the Ending Messages */
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

    std::cout<<"Goodbye"<<std::endl;
}

void GameEngine::gameEnds(Player* player1, Player* player2, Player* player3, Player* player4){
    std::cout<<"\nGame Over"<<std::endl;
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player3->getPlayerName()<<": "<<player3->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player4->getPlayerName()<<": "<<player4->getPlayerScore()<<std::endl;

    int playerOneScore = player1->getPlayerScore();
    int playerTwoScore = player2->getPlayerScore();
    int playerThreeScore = player3->getPlayerScore();
    int playerFourScore = player4->getPlayerScore();

    if (playerOneScore > playerTwoScore && playerOneScore > playerThreeScore && playerOneScore > playerFourScore){
        std::cout<<"Player "<<player1->getPlayerName()<< " won!"<<std::endl;
    } 
    else if (playerTwoScore > playerOneScore && playerTwoScore > playerThreeScore && playerTwoScore > playerFourScore){
        std::cout<<"Player "<<player2->getPlayerName()<< " won!"<<std::endl;
    } 
    else if (playerThreeScore > playerOneScore && playerThreeScore > playerTwoScore && playerThreeScore > playerFourScore){
        std::cout<<"Player "<<player3->getPlayerName()<< " won!"<<std::endl;
    } 
    else{
        std::cout<<"Player "<<player4->getPlayerName()<< " won!"<<std::endl;
    }

    std::cout<<"Goodbye"<<std::endl;
}


/* Validates Input in 3 ways: Placed Tile should be in Hands, Command should be correctly formatted,
Coordinates given should legal,
Checks for correct user input coordinated given */
bool GameEngine::checkInputforPlacing(std::string input, LinkedList* hand){
    if(checksString(input) && checksLetterinHand(input[6], hand) && checkBoardCoordinates(input)){
        return true;
    } 
    return false;
}

// bool GameEngine::checkWord(std::string input){
//     bool retVal = false;
//     char inputWord[] = {0};
//     for (int i=0; i != '\0'; i++){
//         inputWord[i] = {*input.c_str()};
//     }
//     const std::string cstr = inputWord;
//     std::ifstream adjectiveFile("web2");

//     std::string fileWord;
//     while(adjectiveFile >> fileWord) {
//             std::cout << cstr << std::endl;
//         if (cstr.find(fileWord) != std::string::npos) {
//             // std::cout << "The word " << input << " is in the file" << std::endl;
//             retVal = true;
//         } 
//     }

//     if (retVal == false){
//         std::cout << "The word does not exist" << std::endl;
//     }

//     adjectiveFile.close();
    
//     return retVal;
// }


/* Checks if Row entered is Correct */
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


/* Checks if Column entered is Correct */
bool GameEngine::checkCol(char col){
    for (char i = 'A'; i <= 'O'; ++i){
        if (col == i){
            return true;
        }
    }
    return false;
}


/* Check Board Coordinated (Rows, Cols) */
bool GameEngine::checkBoardCoordinates(std::string input){

    if(checkRow(input) && checkCol(input[11])){
        return true;
    } if (enableEnhancement == true) {
        std::cout << "Board Coordinates Don't Exist: You can only enter A-O and 0-14" << std::endl;
        errorMsg = true;
        return false;
    }
    return false;
}


/* Checks String entered is correct */
bool GameEngine::checksString(std::string input){
    if ((input.substr(0,5).compare("place") == 0) && (input.substr(8,2).compare("at") == 0)){
        return true;
    }
    return false;
}


/* Checks Letter is present in Hand or not */
bool GameEngine::checksLetterinHand(char c, LinkedList* hand){
    for (int i = 0; i < 7; ++i){
        if (c == hand->get(i)->getLetter()){
            return true;
        }
    }
    if (enableEnhancement == true) {
        std::cout<<"Tile is not in Hand"<<std::endl;
        errorMsg = true;
        return false;
    }
    return false;
}


/* Convert Char to Integer value */
int GameEngine::convertChartoInt(char c){
    int j=0;
    for (char i = 'A'; i <= c; i++){
        ++j;
    }
    return j;
}


/* Convert Integer to Char */
char GameEngine::convertInttoChar(int i){
    char c = 'A';
    for (int j=0; j<=i; ++i){
        ++c;
    }
    return c;
}
