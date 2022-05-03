#include "GameEngine.h"
// #include "Board.h"
#include "TileBag.h"

//Constructor for New Game only
GameEngine::GameEngine(Player* player1, LinkedList* hand1, Player* player2, LinkedList* hand2){

    //Created a New Board and a TileBag
    TileBag* tileBag = new TileBag();
    Board* newBoard = new Board();

    bool gameEnd = false;
    bool playerOneChance = true;
    bool playerTwoChance = false;

    while (gameEnd == false){
        for (int i = 0; i < 7; ++i){
            //Setting Tiles in Player's Hands
            player1->getPlayerHand()->add_front(tileBag->getTile());
            player2->getPlayerHand()->add_front(tileBag->getTile());
        }
        
        //If tileBag is empty then game ends
        if (tileBag->getTile() == nullptr){
            gameEnd = true;
        }

        else if(player1->getPlayerHand()->size() == 0 || player2->getPlayerHand()->size() == 0){
            gameEnd = true;
        }
        
        else{
            //Checking for Turns
            if (playerOneChance == true){
                std::cout<<player1->getPlayerName()<<", it's your turn"<<std::endl;
                std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
                std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;
                // newBoard->printBoard();
                
                //Displaying Hand
                //Left empty needs to completed
            }
            else{
                
            }
            
            
        }
        

    }

    gameEnds(player1, player2);
}

//Displays the Ending Messages
void GameEngine::gameEnds(Player* player1, Player* player2){
    std::cout<<"Game Over"<<std::endl;
    std::cout<<"Score for "<<player1->getPlayerName()<<": "<<player1->getPlayerScore()<<std::endl;
    std::cout<<"Score for "<<player2->getPlayerName()<<": "<<player2->getPlayerScore()<<std::endl;

    int playerOneScore = player1->getPlayerScore();
    int playerTwoScore = player2->getPlayerScore();

    if (playerOneScore > playerTwoScore){
        std::cout<<"Player "<<player1->getPlayerName()<< "won!"<<std::endl;
    }
    else{
        std::cout<<"Player "<<player2->getPlayerName()<< "won!"<<std::endl;
    }

    std::cout<<"Goodbye 😄"<<std::endl;
}
