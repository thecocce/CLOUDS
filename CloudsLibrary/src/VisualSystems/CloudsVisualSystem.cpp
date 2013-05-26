
#include "CloudsVisualSystem.h"

CloudsVisualSystem::CloudsVisualSystem(){
	isPlaying = false;
}

CloudsVisualSystem::~CloudsVisualSystem(){
	
}

string CloudsVisualSystem::getVisualSystemDataPath()
{
    return "../../../CloudsData/visualsystems/"+getSystemName()+"/";
}

string CloudsVisualSystem::getDataPath()
{
    return "../../../CloudsData/";
}

bool CloudsVisualSystem::isReleventToKeyword(string keyword){
	return ofContains(relevantKeywords, keyword);
}

void CloudsVisualSystem::setup(){
	ofAddListener(ofEvents().exit, this, &CloudsVisualSystem::exit);
}

void CloudsVisualSystem::playSystem(){
	if(!isPlaying){
		ofRegisterMouseEvents(this);
		ofRegisterKeyEvents(this);
		ofAddListener(ofEvents().update, this, &CloudsVisualSystem::update);
		ofAddListener(ofEvents().draw, this, &CloudsVisualSystem::draw);
		
		isPlaying = true;
		
		begin();
	}
}

void CloudsVisualSystem::stopSystem(){
	if(isPlaying){
		
		end();
		
		ofUnregisterMouseEvents(this);
		ofUnregisterKeyEvents(this);
		ofRemoveListener(ofEvents().update, this, &CloudsVisualSystem::update);
		ofRemoveListener(ofEvents().draw, this, &CloudsVisualSystem::draw);
		
		isPlaying = false;
	}
}

float CloudsVisualSystem::getSecondsRemaining(){
	return secondsRemaining;
}

void CloudsVisualSystem::setSecondsRemaining(float seconds){
	secondsRemaining = seconds;
}

void CloudsVisualSystem::setCurrentKeyword(string keyword){
	currentKeyword = keyword;
}

string CloudsVisualSystem::getCurrentKeyword(){
	return currentKeyword;
}

void CloudsVisualSystem::setCurrentTopic(string topic){
	currentTopic = topic;
}

string CloudsVisualSystem::getCurrentTopic(){
	return currentTopic;
}

vector<string>& CloudsVisualSystem::getRelevantKeywords(){
	return relevantKeywords;
}

