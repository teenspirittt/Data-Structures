//переменная и константы генератора LineRand()
static INT_64 RRand=15750 const INT_64 mRand =(1<<63) -1;
const INT_64 aRand=6364136223846793005;
const INT_64 cRand=1442695040888963407;
//функция установки первого случайного числа от часов
//компьютера
void sRand () { srand(time(0)); RRand=(INT_64)rand();}
//функция генерации случайного числа
//линейный конгруэнтный генератор Xi+1=(a*Xi+c)%m
//habr.com/ru/post/208178
INT_64 LineRand ()
{
INT_64 y1,y2;
y1= (aRand*RRand+cRand)%mRand;
y2= (aRand*y1+cRand)%mRand;
RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 &
0xFFFFFFFF00000000LL)>>32;

void test_rand(int n)
{
//создание дерева для 64 – разрядных ключей типа INT_64
BST< INT_64,int > tree;
//массив для ключей, которые присутствуют в дереве
INT_64* m=new INT_64 [n];
91
//установка первого случайного числа
sRand();
//заполнение дерева и массива элементами
//со случайными ключами
for(int i=0; i<n; i++)
{
m[i]=LineRand();
tree.add(m[i],1);
}
//вывод размера дерева до теста
cout<<"items count:"<<tree.Size()<<endl;
//обнуление счётчиков трудоёмкости вставки,
//удаления и поиска
double I=0;
double D=0;
double S=0;
//генерация потока операций, 10% - промахи операций
for(int i=0;i<n/2;i++)
if(i%10==0) //10% промахов
{
tree.remove(LineRand ());
D+=tree.CountNodes();
tree.add(m[rand()%n],1);
I+=tree.CountNodes();
try{
tree.getItem(LineRand ());
S+=tree.CountNodes();
}
//обработка исключения при ошибке операции поиска
catch(int){S+=tree.CountNodes();}}
else //90% успешных операций
{
int ind=rand()%n;
tree.remove(m[ind]);
D+=tree.CountNodes();
INT_64 key=LineRand ();
tree.add(key,1);
I+=tree.CountNodes();
m[ind]=key;
try{
tree.getItem(m[rand()%n]);
S+=tree.CountNodes();
}
92
//обработка исключения при ошибке операции поиска
catch(int){S+=tree.CountNodes();}
} //конец теста
//вывод результатов:
//вывод размера дерева после теста
cout<<"items count:"<<tree.Size()<<endl;
//теоретической оценки трудоёмкости операций BST
cout<<"1.39*log2(n)="<<1.39*(log((double)
n)/log(2.0))<<endl;
//экспериментальной оценки трудоёмкости вставки
cout<<"Count insert: " << I/(n/2) <<endl;
//экспериментальной оценки трудоёмкости удаления
cout<<"Count delete: " << D/(n/2) <<endl;
//экспериментальной оценки трудоёмкости поиска
cout<<"Count search: " << S/(n/2) <<endl;
//освобождение памяти массива m[]
delete[] m;
}

void test_ord(int n)
{
//создание дерева для 64 – разрядных ключей типа INT_64
BST< INT_64,int > tree;
//массив для ключей, которые присутствуют в дереве
INT_64* m=new INT_64 [n];
//заполнение дерева и массива элементами
// с возрастающими чётными ключами
//на интервале [0, 10000, 20000, ... ,10000*n]
for(int i=0; i<n; i++) {
m[i]= i*10000;
tree.add(m[i],1);
}
//вывод размера дерева до теста
cout<<"items count:"<<tree.Size()<<endl;
//обнуление счётчиков трудоёмкости вставки,
// удаления и поиска
double I=0;
double D=0;
double S=0;
93
//установка первого случайного числа
sRand ();
//генерация потока операций, 10% - промахи операций
for(int i=0;i<n/2;i++)
{
if(i%10==0) //10% промахов
{int k=LineRand()%(10000*n);
k=k+!(k%2); //случайный нечётный ключ
tree.remove(k);
D+=tree.CountNodes();
tree.add(m[rand()%n],1);
I+=tree.CountNodes();
k=LineRand()%(10000*n);
k=k+!(k%2); // случайный нечётный ключ
try{
tree.getItem(k);
S+=tree.CountNodes();
}
//обработка исключения при ошибке операции поиска
catch(int){S+=tree.CountNodes();}
}
else //90% успешных операций
{
int ind=rand()%n;
tree.remove(m[ind]);
D+=tree.CountNodes();;
int k=LineRand()%(10000*n);
k=k+k%2; // случайный чётный ключ
tree.add(k,1);
I+=tree.CountNodes();;
m[ind]=k;
try{
tree.getItem(m[rand()%n]);
S+=tree.CountNodes();;
}
//обработка исключения при ошибке операции поиска
catch(int){S+=tree.CountNodes();}
}
}
//вывод результатов:
// вывод размера дерева после теста
cout<<"items count:"<<tree.Size()<<endl;
94
//теоретической оценки трудоёмкости операций BST
cout<<"n/2 ="<<n/2<<endl;
//экспериментальной оценки трудоёмкости вставки
cout<<"Count insert: " << I/(n/2) <<endl;
//экспериментальной оценки трудоёмкости удаления
cout<<"Count delete: " << D/(n/2) <<endl;
//экспериментальной оценки трудоёмкости поиска
cout<<"Count search: " << S/(n/2) <<endl;
//освобождение памяти массива m[]
delete[] m;
} //конец теста


int main() {
    return 0;
}
