#include <iostream>
#include <string>

using namespace std;

struct Time {
    int hours, minutes;
};

struct Train {
    string number, destination;
    float distance;
    Time departure, arrival;
    int travelTime;
};

void calcTravelTimes(Train arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].travelTime = (arr[i].arrival.hours * 60 + arr[i].arrival.minutes)
                            - (arr[i].departure.hours * 60 + arr[i].departure.minutes);
        if (arr[i].travelTime < 0) arr[i].travelTime += 24 * 60;
    }
}

void selectionSortTrains(Train arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j].travelTime > arr[max_idx].travelTime)
                max_idx = j;
        swap(arr[max_idx], arr[i]);
    }
}

void printTrains(Train arr[], int n) {
    cout << "Number\tDestination\tDist\tDep\t\tArr\t\tTime(min)\n";
    cout << string(65, '-') << "\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].number << "\t"
                << arr[i].destination << "\t\t"
                << arr[i].distance << "\t"
                << arr[i].departure.hours << ":" << arr[i].departure.minutes << "\t\t"
                << arr[i].arrival.hours << ":" << arr[i].arrival.minutes << "\t\t"
                << arr[i].travelTime << "\n";
}

struct TV {
    string manufacturer;
    int screenSize;
    float price;
};

void insertionSortTVs(TV arr[], int n) {
    for (int i = 1; i < n; i++) {
        TV key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].screenSize > key.screenSize)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void gnomeSortTVsDesc(TV arr[], int left, int right) {
    int i = left + 1;
    while (i <= right) {
        if (i == left || arr[i].price <= arr[i - 1].price) i++;
        else {
            swap(arr[i], arr[i - 1]);
            i--;
        }
    }
}

void sortTVs(TV arr[], int n) {
    insertionSortTVs(arr, n);
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || arr[i].screenSize != arr[i - 1].screenSize) {
            gnomeSortTVsDesc(arr, start, i - 1);
            start = i;
        }
    }
}

void printTVs(TV arr[], int n) {
    cout << "Manufacturer\tSize\tPrice\n";
    cout << string(35, '-') << "\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].manufacturer << "\t\t"
                << arr[i].screenSize << "\"\t"
                << arr[i].price << " UAH\n";
}

int main() {
    int numTrains;
    cout << "Enter number of trains: ";
    cin >> numTrains;
    cin.ignore();

    Train *trains = new Train[numTrains];
    for (int i = 0; i < numTrains; i++) {
        cout << "\nTrain " << i + 1 << ":\n";
        cout << " Number: ";
        cin >> trains[i].number;
        cout << " Destination: ";
        cin >> trains[i].destination;
        cout << " Distance: ";
        cin >> trains[i].distance;
        cout << " Departure (h m): ";
        cin >> trains[i].departure.hours >> trains[i].departure.minutes;
        cout << " Arrival (h m): ";
        cin >> trains[i].arrival.hours >> trains[i].arrival.minutes;
        trains[i].travelTime = 0;
    }

    calcTravelTimes(trains, numTrains);

    int maxIdx = 0;
    for (int i = 1; i < numTrains; i++)
        if (trains[i].travelTime > trains[maxIdx].travelTime)
            maxIdx = i;
    cout << "\nLongest travel (manual): " << trains[maxIdx].number
            << " -> " << trains[maxIdx].destination << "\n";

    selectionSortTrains(trains, numTrains);
    cout << "\nTrains sorted by travel time (desc):\n";
    printTrains(trains, numTrains);
    delete[] trains;

    int numTVs;
    cout << "\nEnter number of TVs: ";
    cin >> numTVs;
    cin.ignore();

    TV *tvs = new TV[numTVs];
    for (int i = 0; i < numTVs; i++) {
        cout << "\nTV " << i + 1 << ":\n";
        cout << " Manufacturer: ";
        cin >> tvs[i].manufacturer;
        cout << " Screen size: ";
        cin >> tvs[i].screenSize;
        cout << " Price: ";
        cin >> tvs[i].price;
    }

    sortTVs(tvs, numTVs);
    cout << "\nTVs sorted by size asc, price desc:\n";
    printTVs(tvs, numTVs);
    delete[] tvs;

    return 0;
}
