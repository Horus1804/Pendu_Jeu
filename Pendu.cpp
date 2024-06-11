#include <iostream>
#include <vector>
using namespace std;
int main() {

    //Initialize game
    string wordToGuess;
    cout << "Entrez un mot : ";
    cin >> wordToGuess;
    for (int i = 0; i < wordToGuess.size(); i++) {
        wordToGuess[i] = toupper(wordToGuess[i]);
    }
    system("cls");
    int health = 10;
    string wordHidden(wordToGuess.size(), '_');
    vector<char> charUsed;

    //Game loop
    while (!(wordHidden == wordToGuess) && health > 0) {

        //Show already used letters
        if (!charUsed.empty()) {
            cout << "Lettres deja entrees : ";
            for (int i = 0; i < charUsed.size(); i++) {
                cout << charUsed[i] << " ";
            }
            cout << endl;
        }

        //Ask for letter
        cout << "vies restantes : " << health << endl;
        cout << "word : " << wordHidden << endl;
        cout << "Entrez une lettre : ";
        char letter;
        cin >> letter;
        letter = toupper(letter);

        //Check already used letter
        vector<char>::iterator it = find(charUsed.begin(), charUsed.end(), letter);
        if (it != charUsed.end()) {
            system("cls");
            cout << "caractere deja utilise, recommencez" << endl;
            continue;
        }
        charUsed.push_back(letter);

        //Check letter in wordToGuess
        bool foundLetter = false;
        for (int i = 0; i < wordToGuess.size(); i++) {
            if (letter == wordToGuess[i]) {
                foundLetter = true;
                wordHidden[i] = letter;
            }
        }
        if (!foundLetter) health--;
        system("cls");
    }

    //End game
    if (health > 0) cout << "J2 GAGNE, le mot a ete devine en " << 11 - health << " tour(s) !" << endl;
    else cout << "J1 GAGNE, le mot etait " << wordToGuess << " !" << endl;
}