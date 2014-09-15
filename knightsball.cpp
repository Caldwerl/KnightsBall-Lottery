#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct playerData {

  string firstName;
  string lastName;

  int lottoNum[6];
  int numMatches;
  string winnings;
};

void setLottoNums (int lottoNums[]);

void readInPlayers (ifstream& inputFile, playerData players[], int numPlayers);

void checkLottoNums (int lottoNums[], playerData players[], int numPlayers);

void setWinnings (playerData players[], int numPlayers);

void writeOutput (ofstream& outputFile, playerData players[], int numPlayers);




int main() {

  ifstream inputFile;
  inputFile.open("knightsball.in");

  ofstream outputFile;
  outputFile.open("knightsball.out");

  int numPlayers;
  int lottoNums[6];

  setLottoNums(lottoNums);

  inputFile >> numPlayers;

  playerData players[numPlayers];

  readInPlayers(inputFile, players, numPlayers);

  checkLottoNums(lottoNums, players, numPlayers);

  setWinnings(players, numPlayers);

  writeOutput(outputFile, players, numPlayers);

  inputFile.close();
  outputFile.close();

  return(0);
}





void setLottoNums (int lottoNums[]) {

  for (int i = 0; i < 6; i++){

    lottoNums[i] = rand() % 53 + 1;
  }
}
//End setLottoNums

void readInPlayers (ifstream& inputFile, playerData players[], int numPlayers) {

  for (int i = 0; i < numPlayers; i++) {

    inputFile >> players[i].lastName >> players[i].firstName;

    for (int j = 0; j < 6; j++) {
      inputFile >> players[i].lottoNum[j];
    }

  }
}
//End readInPlayers

void checkLottoNums (int lottoNums[], playerData players[], int numPlayers) {

  for (int i = 0; i < numPlayers; i++){

    players[i].numMatches = 0;

    for (int j = 0; j < 6; j++){

      for(int k = 0; k < 6; k++){

        if (lottoNums[j] == players[i].lottoNum[k]) {
          players[i].numMatches++;
        }
      }
    }
  }
}
//End checkLottoNums

void setWinnings (playerData players[], int numPlayers) {

  for (int i = 0; i < numPlayers; i++) {

    switch (players[i].numMatches) {

      case 3:
        players[i].winnings = "$10";
        break;

      case 4:
        players[i].winnings = "$100";
        break;

      case 5:
        players[i].winnings = "$10,000";
        break;

      case 6:
        players[i].winnings = "$1,000,000";
        break;

      default:
        players[i].winnings = "$0";
        break;
    }
  }
}
//End setWinnings

void writeOutput (ofstream& outputFile, playerData players[], int numPlayers) {

  outputFile << "Knightsball Lotto Results" << endl << endl;

  for(int i = 0; i < numPlayers; i++) {

    outputFile << players[i].firstName << " " << players[i].lastName
               << " matched " << players[i].numMatches << " numbers and won "
               << players[i].winnings << endl;
  }
}
//End writeOutput
