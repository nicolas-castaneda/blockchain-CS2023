#include "app.h"

void lineal_test(){
    Blockchain<Data> * chain = new Blockchain<Data>();
    string sender, receiver;
    Data data;
    ifstream file("../transactions10000.txt");
    while(file >> sender >> receiver >> data){
        chain->insert(new Transaction<Data>(sender,receiver,data));
    }
    cout<<chain->sender_equal_to_lineal("Georgiana")<<endl;

    cout<<chain->sender_equal_to("Georgiana")<<endl;
}

int main()
{
    lineal_test();
//    App();
    return 0;
}

