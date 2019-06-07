/*
An animal shelter holds only dogs and cats, and operates on a strictly "first
in, first out" basis. People must adopt either the "oldest" (based on arrival
time) of all animals at the shelter, or they can select whether they would
prefer a dog or a cat (and will receive the oldest animal of that type). They
cannot select which specificanimal they would like. Create the data
structures to maintain this system and implement operations such as enqueue,
dequeueAny, dequeueDog and dequeueCat.You mayusethe built-in LinkedList data
structure.

APPROACH:
We use 2 queues, one for each animal and each queue has a pair with a
stamp of the order the animal arrived so we can figure out which to dequeue
when someone whats to adopt any animal (dequeueAny).

TO COMPILE: clang++ -std=c++11 6.Shelter.cpp -o main

 */

#include <iostream>
#include <queue>

using namespace::std;

enum AnimalType { Dog, Cat };

class Shelter {
private:
    queue<pair<int, string> > cats;
    queue<pair<int, string> > dogs;
    static int timeStamp;
public:
    Shelter() {}

    void PrintShelterContents() {
        queue<pair<int, string> > tmpCats = cats;
        queue<pair<int, string> > tmpDogs = dogs;

        cout << "Cats |=>";
        while(!tmpCats.empty()) {
            cout << "(" << tmpCats.front().first << "," << tmpCats.front().second << ") -> " ;
            tmpCats.pop();
        }
        cout << endl;

        cout << "Dogs |=>";
        while(!tmpDogs.empty()) {
            cout << "(" << tmpDogs.front().first << "," << tmpDogs.front().second << ") -> " ;
            tmpDogs.pop();
        }
        cout << endl;
    }

    void CollectAnimal(string name, const AnimalType &at) {
        switch(at) {
        case AnimalType::Dog:
            dogs.push(pair<int, string>(timeStamp, name));
            break;
        case AnimalType::Cat:
            cats.push(pair<int, string>(timeStamp, name));
            break;
        default:
            cout << "Unknown animal collected" << endl;
            break;
        }
        timeStamp++;
    }

    void AdoptCat() {
        if(cats.empty()) {
            cout << "No cats available to adopt" << endl;
            return;
        }
        cout << "Adopted Cat: " << cats.front().second << endl;
        cats.pop();
    }
    void AdoptDog() {
        if(dogs.empty()) {
            cout << "No cats available to adopt" << endl;
            return;
        }
        cout << "Adopted Dog: " << dogs.front().second << endl;
        dogs.pop();
    }
    void AdoptAny() {
        if(dogs.empty() && cats.empty()) {
            cout << "No animals available to adopt." << endl;
            return;
        }
        if(dogs.empty()) {
            AdoptCat();
            return;
        }
        if(cats.empty()) {
            AdoptDog();
            return;
        }
        pair<int, string> oldestCat = cats.front();
        pair<int, string> oldestDog = dogs.front();
        cout << "|Adopt Any| ";
        if(oldestCat.first < oldestDog.first)
            AdoptCat();
        else
            AdoptDog();

    }

};

int Shelter::timeStamp = 0;

int main(int argc, char* argv[]) {
    Shelter s;
    s.CollectAnimal("Cat1", AnimalType::Cat);
    s.CollectAnimal("Dog1", AnimalType::Dog);

    s.CollectAnimal("Cat2", AnimalType::Cat);
    s.CollectAnimal("Dog3", AnimalType::Dog);
    s.CollectAnimal("Cat3", AnimalType::Cat);
    s.CollectAnimal("Cat4", AnimalType::Cat);
    s.CollectAnimal("Dog2", AnimalType::Dog);
    s.CollectAnimal("Cat5", AnimalType::Cat);
    s.CollectAnimal("Cat6", AnimalType::Cat);

    s.CollectAnimal("Dog4", AnimalType::Dog);
    s.CollectAnimal("Dog5", AnimalType::Dog);
    s.CollectAnimal("Dog6", AnimalType::Dog);

    s.PrintShelterContents();

    s.AdoptCat();
    s.AdoptDog();
    s.AdoptAny();
    s.AdoptAny();
    s.AdoptAny();
    s.AdoptDog();
    s.PrintShelterContents();
}
