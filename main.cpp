
#include <iostream>
#include <string>
struct Product{
std::string name;
double price;
int date;
};
void displ_prod(Product* p1){
  std::cout<<"Продукт: "<<p1->name<<" \n цена: "<<p1->price<<" \n день выпуска: "<<p1->date<<'\n';
}
class Hash{
public: Product* hash_table;
         int size;
public: Hash(int s):size(s){ hash_table=new Product[size]();}
         int HashFunction(int x, int i){
           return (x+i*i)%size;
         }
         void AddEl(Product value){
           for(int i=0;i<size;++i){
               int jump=(HashFunction(value.date,i));
               if (hash_table[jump].date==0 || hash_table[jump].date==9999){
                  hash_table[jump]=value;
                  return;
             }
         }
  }
        Product* FindEl(int value){
           for(int i=0;i<size;++i){
              int ind=(HashFunction(value,i))%(size);
               if (hash_table[ind].date==value){
                   return &hash_table[ind];}
               if(hash_table[ind].date==0)
                 {std::cout<<"Значения не существует"<<'\n';
                 }
         }
         std::cout<<"Значения не существует"<<'\n';
         }
         void display(){
           for(int i=0;i<size;++i){
             std::cout<<i+1<<" -> ";
           displ_prod(hash_table+i);}
         }
         int delel(int value){
           for(int i=0;i<size;++i){
              int ind=HashFunction(value,i)%(size);
               if (hash_table[ind].date==value){
                   hash_table[ind].date=9999;
                     break;
                   }
               else if(hash_table[ind].date==0)
                 {std::cout<<"Значение не существует"<<'\n';
                   return -1;}
         }
}
         ~Hash(){
           delete[] hash_table;
         }
};
int main(){
  std::cout<<"Введите кол-во элементов"<<'\n';
  int n;
  std::cin>>n;
  Hash h1(n);
  char ch;
  int k=0;
  do{
      Product p1;
      std::cout<<"Введите название продукта"<<'\n';
      std::cin>>p1.name;
      std::cout<<"Введите цену продукта"<<'\n';
      std::cin>>p1.price;
      std::cout<<"Введите дату выпуска"<<'\n';
      std::cin>>p1.date;
      h1.AddEl(p1);
      k++;
      std::cout<<"Продолжить? Y/N\n";
      std::cin>>ch;
      if(k>n){
          std::cout<<"Хеш перегружен\n ";
          break;
        }
    }
  while(ch=='Y');
  h1.display();
   char dd;
  std::cout<<"Продолжить? \n";
  std::cin>>dd;
  while(dd=='Y'){
  std::cout<<"\n\n Выберите \n 1-найти элемент ,2-удалить элемент";
  int ch;
  int dat;
 std::cin>>ch;
  std::cout<<"\n Введите поле данных\n";
  std::cin>>dat;
    switch (ch) {
    case 1:{ Product* pp=h1.FindEl(dat); displ_prod(pp);
      break;}
      case 2: {h1.delel(dat);std::cout<<"Элемент успешно удален\n"; break;}
    default:std::cout<<"Неправильный выбор! \n";
      break;
    }
  std::cout<<"\n Далее?\n";
  std::cin>>dd;}
}
