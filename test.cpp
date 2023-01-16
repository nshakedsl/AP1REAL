//todo: delete me
#include <iostream>
#include "StandardIO.h"
#include "UploadFile.h"
int main(){
    Command *cmd = new UploadFile(nullptr, nullptr);
    try  {
        throw 10;
    }
    catch (int i)  {
        if (i==10){
            std::cout << "10";
        } else if (i == 5) {
            std::cout << "5";
        }
    }
    catch (...)  {
        std::cout << "Default Exception\n";
    }
    return 0;
}