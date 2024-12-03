/*You are tasked with designing a simple system for a 
zoo that manages different types of animals. Each 
animal has a sound that it makes, and you need to 
implement this behavior using object-oriented 
programming concepts in C++. Specifically, you are 
required to utilize Pure virtual functions to enable 
polymorphism, allowing different animal classes to 
implement their own version of a function that 
simulates the sound the animal makes.Base class 
animal with Makesound() and Derived Classes 
dog,cat,cow etc.*/
#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal
{
public:
    // Pure virtual function
    virtual void MakeSound() const = 0;

    // Virtual destructor
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal
{
public:
    string breed;
    int age;

    // Function to set breed and age
    void SetDetails(const string &dogBreed, int dogAge)
    {
        breed = dogBreed;
        age = dogAge;
    }

    void MakeSound() const override
    {
        cout << "Dog: Woof! Woof! (Breed: " << breed << ", Age: " << age << " years)" << endl;
    }
};

// Derived class Cat
class Cat : public Animal
{
public:
    string breed;
    int age;

    // Function to set breed and age
    void SetDetails(const string &catBreed, int catAge)
    {
        breed = catBreed;
        age = catAge;
    }

    void MakeSound() const override
    {
        cout << "Cat: Meow! Meow! (Breed: " << breed << ", Age: " << age << " years)" << endl;
    }
};

// Derived class Cow
class Cow : public Animal
{
public:
    string type;
    int age;

    // Function to set type and age
    void SetDetails(const string &cowType, int cowAge)
    {
        type = cowType;
        age = cowAge;
    }

    void MakeSound() const override
    {
        cout << "Cow: Moo! Moo! (Type: " << type << ", Age: " << age << " years)" << endl;
    }
};

int main()
{
    Animal *zoo[100]; // Array to hold up to 100 animals
    int count = 0;    // Counter for the number of animals in the zoo
    int choice;

    do
    {
        // Display menu
        cout << "\nZoo Animal Manager" << endl;
        cout << "1. Add a Dog" << endl;
        cout << "2. Add a Cat" << endl;
        cout << "3. Add a Cow" << endl;
        cout << "4. Hear Zoo Sounds" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string breed;
            int age;

            cout << "Enter the breed of the dog: ";
            cin >> breed;

            cout << "Enter the age of the dog: ";
            cin >> age;

            Dog *dog = new Dog();
            dog->SetDetails(breed, age);
            zoo[count++] = dog;

            cout << "Dog added to the zoo!" << endl;
        }
        case 2:
        {
            string breed;
            int age;

            cout << "Enter the breed of the cat: ";
            cin >> breed;

            cout << "Enter the age of the cat: ";
            cin >> age;

            Cat *cat = new Cat();
            cat->SetDetails(breed, age);
            zoo[count++] = cat;

            cout << "Cat added to the zoo!" << endl;
        }
        case 3:
        {
            string type;
            int age;

            cout << "Enter the type of the cow (e.g., Jersey, Holstein): ";
            cin >> type;

            cout << "Enter the age of the cow: ";
            cin >> age;

            Cow *cow = new Cow();
            cow->SetDetails(type, age);
            zoo[count++] = cow;

            cout << "Cow added to the zoo!" << endl;
        }
        case 4:
        {
            if (count == 0)
            {
                cout << "The zoo is empty! Add some animals first." << endl;
            }
            else
            {
                cout << "\nZoo Sounds:" << endl;
                for (int i = 0; i < count; i++)
                {
                    zoo[i]->MakeSound();
                }
            }
        }
        case 5:
        {

            cout << "Exiting the zoo manager. Goodbye!" << endl;
            break;

        } 
        case 6: {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    } while (choice != 5);

    return 0;
}
