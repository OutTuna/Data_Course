#include <iostream>
#include <string>
using namespace std;

struct Music {
    int media;
    string title;
    string artist;
    int time;
    int tracks;
    float price;
    Music *next;
} *first, *newFirst;

int main() {
    first = 0;
    newFirst = 0;
    Music *q;

    for (int i = 0; i < 4; i++) {
        Music *c = new Music;
        cout << "Enter media(1-vinyl, 2-cassette, 3-cd), title, artist, time(sec), tracks, price:\n";
        cin >> c->media >> c->title >> c->artist >> c->time >> c->tracks >> c->price;
        c->next = first;
        first = c;
    }

    cout << "\nCurrent music stack:\n";
    q = first;
    while (q != 0) {
        cout << q->artist << " - " << q->title << " | Media: " << q->media << " | Time: " << q->time << "s | Price: " <<
                q->price << '\n';
        q = q->next;
    }
    cout << '\n';

    string targetArtist;
    cout << "Enter target artist: ";
    cin >> targetArtist;

    int totalTime = 0;

    while (first != 0) {
        q = first;
        first = first->next;

        if (q->artist == targetArtist) {
            totalTime += q->time;
        }

        if (q->media == 2) {
            q->next = newFirst;
            newFirst = q;
        } else {
            delete q;
        }
    }

    cout << "Total time for artist " << targetArtist << ": " << totalTime << " seconds\n";

    float cassettePrice = 0;
    int cassetteCount = 0;

    cout << "\nNew cassette stack:\n";
    q = newFirst;
    while (q != 0) {
        cout << q->artist << " - " << q->title << " | Price: " << q->price << '\n';
        cassettePrice += q->price;
        cassetteCount++;
        q = q->next;
    }

    if (cassetteCount > 0) {
        cout << "Average cassette price: " << cassettePrice / cassetteCount << '\n';
    }

    while (newFirst != 0) {
        q = newFirst;
        newFirst = newFirst->next;
        delete q;
    }

    return 0;
}
