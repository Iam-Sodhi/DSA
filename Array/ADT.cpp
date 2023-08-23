#include <iostream>
#include <stdlib.h>
using namespace std;
//******Abstract data type of arrays
class myarray
{
public:
    int t_size;
    int t_size;
    int used_size;
    int *ptr;
    myarray(int ts, int us)
    {
        t_size = ts;
        used_size = us;
        // ptr = (int *)malloc(ts * sizeof(int));
        ptr= new int[ts];
    }
   void set_value( )
    {   
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter " << i + 1 << " number:";
            cin >>ptr[i];
        }
    }
    void show_value(){
        for (int i = 0; i < used_size; i++)
        {
            cout<<ptr[i]<<" ";
        }
        
    }
};
 
int main()
{ myarray marks(10,2);
   marks.set_value();
   cout<<"Now It's time to show the values of our abstract array data type:"<<endl;
   marks.show_value();
    return 0;
}