#include <iostream>
#include <fstream>
#include "Controller.hh"
#include <string>
#include <random>
#include "FlowshopGraph.hh"

#define TEST_COUNT 10

//Funkcja wypisujaca do pliku wyniki testow zasady Johnsona dla losowych danych wejsciowych
void printTest(std::ofstream& file, unsigned int machines, unsigned int tests)
{
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(2,10);
    Order order;

    if(machines > 3 ) {
        std::cerr << "Invalid machine count in test function!\n";
        return;
    }

    for(int i = 0; i < tests; i++)
    {
        Controller controller(machines,distribution(generator));

        controller.printData(file);

        order = controller.johnsonOrder();
        file << "Johnsons order:\n";
        controller.printOrder(file,order);
        file << "\n\n\n";
    }
}

//Funkcja wypisujaca do pliku wyniki testow permutacji dla losowych danych wejsciowych
void printPermTest(std::ofstream& file, unsigned int tests)
{
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<> distribution(2,5);
    std::vector<Order> order;
    Order ord;

    for(int i = 0; i < 3; i++)
    {
        Controller controller(distribution(generator),distribution(generator));

        controller.printData(file);

        order = controller.permutationOrder();
        file << "Permutation order:\n";

        for(int m = 0; m < order.size(); m++) {
            controller.printOrder(file,order[m]);
        }

        file << "\n\n\n";
    }
}

//Funkcja wypisujaca do pliku wyniki testow zasady Johnsona i permutacji dla danych wejsciowych z pliku
void readTest(std::string filename)
{
    Controller controller(filename);
    Order ord;
    std::vector<Order> order;

    std::cout<<"Reading file: "<<filename<<std::endl;

    controller.printData(std::cout);

    ord = controller.johnsonOrder();
    std::cout<<"Johnson order: [";
    controller.printOrder(std::cout,ord);

    order = controller.permutationOrder();
    std::cout << "\nPermutation order:\n";

    for(int m = 0; m < order.size(); m++) {
       controller.printOrder(std::cout,order[m]);
    }

    std::cout << "\n\n\n";
}

void test(std::string filename)
{
    Controller controller(filename);

    std::cout<<"NEH order: ";
    controller.printOrder(std::cout,controller.nehOrder(false));
    std::cout<<"NEH order accelerated: ";
    controller.printOrder(std::cout,controller.nehOrder(true));
    std::cout<<"Johnson order: ";
    controller.printOrder(std::cout,controller.johnsonOrder());
}

void test(int i)
{
    Controller controller(i,100);

    std::cout<<"NEH order: ";
    controller.printOrder(std::cout,controller.nehOrder(false));
    std::cout<<"NEH order accelerated: ";
    controller.printOrder(std::cout,controller.nehOrder(true));
    std::cout<<"Johnson order: ";
    controller.printOrder(std::cout,controller.johnsonOrder());
}

int main()
{
    /*
    test(std::string("ta000"));
    test(std::string("ta001"));
    test(std::string("ta002"));
    test(std::string("ta003"));
    test(std::string("ta004"));
    test(std::string("ta005"));
    test(std::string("ta006"));
    test(std::string("ta007"));
    test(std::string("ta008"));
    test(std::string("ta009"));
    test(std::string("ta010"));
*/

    test(2);
    test(3);

    return 0;
}