#include <iostream>

class Animals
{

private:

public:
    
    virtual void Voice()
    {
        std::cout << "I'am just an animal! For this slot you choose incorrect number!";
    }

};

class Goat : public Animals
{

private:

public:

    void Voice() override
    {
        std::cout << "Baaah!";
    }
};

class Cat : public Animals
{

private:

public:

    void Voice() override
    {
        std::cout << "Meow!";
    }
};

class Dog : public Animals
{

private:

public:

    void Voice() override
    {
        std::cout << "Bark!";
    }
};


int main()
{
    //Initialization
    int S = 0;
    while (S <= 0)
    {
        std::cout << "Number of animals: ";
        std::cin >> S;
        if (S <= 0)
        {
            std::cout << "Number can't be negative or zero!\n";
        }
    }

    Animals** AnimalArray = new Animals*[S];

    //Get animals
    for (int i = 0; i < S; i++)
    {
        int Slot;
        std::cout << "Animal in slot " << i + 1 << " is: \n";
        std::cout << "1. Goat\n" << "2. Cat\n" << "3. Dog\n";
        std::cin >> Slot;

        switch (Slot)
        {

        case 1:
            AnimalArray[i] = new Goat();
            break;

        case 2:
            AnimalArray[i] = new Cat();
            break;

        case 3:
            AnimalArray[i] = new Dog();
            break;

        default:
            AnimalArray[i] = new Animals();
            break;
        }
    }
    
    //Check, if there is only one animal in an array
    if (S == 1)
    {
        std::cout << "Now let's listen how it sound!\n";
    }
    else
    {
        std::cout << "Now let's listen how they sound!\n";
    }

    //Voice function call
    for (int i = 0; i < S; i++)
    {
        AnimalArray[i]->Voice();
        std::cout << "\n";
    }

    //Memory cleaning
    delete[S] AnimalArray;
    AnimalArray = nullptr;
}
