#include"GSM.h"


GSM::GSM(){

}
GSM::GSM(GameStates initialState){
    this->currentState = initialState;
}

void GSM::changeState(){
    if(this->currentState == GameStates::TEST_BENCH){
        this->tb = TestBench();
    } 

    if(this->currentState == GameStates::RE_OPINION){
        this->re = ReOpinion();
    }

}

void GSM::draw(SDL_Renderer* renderer){
    if(this->currentState == GameStates::TEST_BENCH){
        this->tb.draw(renderer);
        if(this->tb.hasStateChanged){
            this->currentState = this->tb.changeState;
            changeState();
        }
    }

    if(this->currentState == GameStates::RE_OPINION){
        this->re.draw(renderer);
    }
}