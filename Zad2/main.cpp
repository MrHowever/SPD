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

int main()
{
    /*
    std::ofstream file1("JohnsonsRule2Tests.txt");
    std::ofstream file2("JohnsonsRule3Tests.txt");
    std::ofstream file3("PermutationsTests.txt");

    printTest(file1,2,TEST_COUNT);
    printTest(file2,3,TEST_COUNT);
    printPermTest(file3,TEST_COUNT);
    readTest(std::string("ta000"));

    Controller controller(1,1);
    //controller.calcTaskTime(11);
    controller.permVsJohnTest();
    */

    Controller controller("ta000");
    Order ord = {0,1,2,3,4};

    //std::cout<<"Longest op on critical: "<<FlowshopGraph::longestCriticalOperation(controller.tasks,ord)<<std::endl;

    //std::cout<<"Longest sum on critical: "<<FlowshopGraph::longestSumOfCriticalOperations(controller.tasks,ord)<<std::endl;

    //std::cout<<"Most on critical: "<<FlowshopGraph::mostCriticalOperations(controller.tasks,ord)<<std::endl;

    //FlowshopGraph graph(controller.tasks,ord);
    //graph.removeNonCriticalEdges();
    //graph.reverseEdges();
    //graph.printGraph(std::cout);


    std::cout<<"NEH order: [";
    controller.printOrder(std::cout,ord);

    std::cout<<"Cmax = "<<controller.calculateTask(ord)<<std::endl;


    return 0;
}