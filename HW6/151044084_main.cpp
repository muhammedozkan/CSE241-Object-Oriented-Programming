//============================================================================
// Name        : cpphomework6.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include <iostream>
#include <string>

#include "Iterator.h"

#include "LinkedList.h"
#include "LinkedList.cpp"

#include "HashSet.h"
#include "HashSet.cpp"

#include "ArrayList.h"
#include "ArrayList.cpp"

using namespace std;
using namespace GTU;

int main()
{
	try
	{
		cout << "Class Test" << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl
			 << endl;
		ArrayList<int> arrlistint;
		cout << "ArrayList<int> oluşturuldu" << endl;
		cout << "ArrayList<int> boş mu? Sonuç:" << arrlistint.isEmpty() << endl;
		arrlistint.add(50);
		arrlistint.add(20);
		arrlistint.add(10);
		arrlistint.add(40);
		arrlistint.add(30);
		arrlistint.add(50);
		cout << "ArrayList<int>'e 50,20,10,40,30,50 değerleri eklendi" << endl;
		cout << "ArrayList<int>'deki eleman sayısı:" << arrlistint.size() << endl;
		cout << "ArrayList<int> boş mu? Sonuç:" << arrlistint.isEmpty() << endl;
		cout << "ArrayList<int> içerisinde 60 değerini içeriyormu? Sonuç:" << arrlistint.contains(60) << endl;
		cout << "ArrayList<int> içerisinde 10 değerini içeriyormu? Sonuç:" << arrlistint.contains(10) << endl;
		cout << "ArrayList<int> içerisinde 30 değeri siliniyor? Sonuç:" << arrlistint.remove(30);
		cout << " Eleman sayısı:" << arrlistint.size() << endl;
		cout << "ArrayList<int> deki elemanlar sırası ile yazdırılıyor" << endl;
		int i = 0;
		for (list<int>::iterator it = arrlistint.iterator(); i < arrlistint.size(); it++, i++)
		{
			cout << *it << endl;
		}
		cout << "ArrayList<int> içeriği tamamen silindi" << endl;
		arrlistint.clear();
		cout << "ArrayList<int>'deki eleman sayısı:" << arrlistint.size() << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl
			 << endl;
		ArrayList<string> arrliststr;
		cout << "ArrayList<string> oluşturuldu" << endl;
		cout << "ArrayList<string> boş mu? Sonuç:" << arrliststr.isEmpty() << endl;
		arrliststr.add("Elma");
		arrliststr.add("Armut");
		arrliststr.add("Karpuz");
		arrliststr.add("Domates");
		arrliststr.add("Salatalık");
		arrliststr.add("Elma");
		cout << "ArrayList<string>'e Elma,Armut,Karpuz,Domates,Salatalık,Elma değerleri eklendi" << endl;
		cout << "ArrayList<string>'deki eleman sayısı:" << arrliststr.size() << endl;
		cout << "ArrayList<string> boş mu? Sonuç:" << arrliststr.isEmpty() << endl;
		cout << "ArrayList<string> içerisinde Patlıcan değerini içeriyormu? Sonuç:" << arrliststr.contains("Patlıcan") << endl;
		cout << "ArrayList<string> içerisinde Karpuz değerini içeriyormu? Sonuç:" << arrliststr.contains("Karpuz") << endl;
		cout << "ArrayList<string> içerisinde Salatalık değeri siliniyor? Sonuç:" << arrliststr.remove("Salatalık");
		cout << " Eleman sayısı:" << arrliststr.size() << endl;
		cout << "ArrayList<string> deki elemanlar sırası ile yazdırılıyor" << endl;
		i = 0;
		for (list<string>::iterator it = arrliststr.iterator(); i < arrliststr.size(); it++, i++)
		{
			cout << *it << endl;
		}
		cout << "ArrayList<int> içeriği tamamen silindi" << endl;
		arrliststr.clear();
		cout << "ArrayList<int>'deki eleman sayısı:" << arrliststr.size() << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl
			 << endl;
		LinkedList<int> lnklistint;
		cout << "LinkedList<int> oluşturuldu" << endl;
		cout << "LinkedList<int> boş mu? Sonuç:" << lnklistint.isEmpty() << endl;
		lnklistint.add(50);
		lnklistint.add(20);
		lnklistint.offer(10); //offer fonksiyonu ile ekleme yapıldı.
		lnklistint.add(40);
		lnklistint.offer(30);
		lnklistint.add(50);
		lnklistint.offer(80);
		cout << "LinkedList<int>'e 50,20,10,40,30,50,80 değerleri eklendi" << endl;
		cout << "LinkedList<int>'deki eleman sayısı:" << lnklistint.size() << endl;
		cout << "LinkedList<int> boş mu? Sonuç:" << lnklistint.isEmpty() << endl;
		cout << "LinkedList<int> içerisindeki en başta olan eleman getiriliyor.(element fonksiyonu) Listeden silinmiyor Eleman:" << lnklistint.element();
		cout << " Eleman sayısı:" << lnklistint.size() << endl;
		cout << "LinkedList<int> içerisindeki en başta olan eleman getiriliyor.(poll fonksiyonu) Listeden siliniyor Eleman:" << lnklistint.poll();
		cout << " Eleman sayısı:" << lnklistint.size() << endl;
		cout << "LinkedList<int> içerisinde 60 değerini içeriyormu? Sonuç:" << lnklistint.contains(60) << endl;
		cout << "LinkedList<int> içerisinde 10 değerini içeriyormu? Sonuç:" << lnklistint.contains(10) << endl;
		cout << "LinkedList<int> içerisinde 30 değeri siliniyor? Sonuç:" << lnklistint.remove(30);
		cout << " Eleman sayısı:" << lnklistint.size() << endl;
		cout << "LinkedList<int> deki elemanlar sırası ile yazdırılıyor" << endl;
		i = 0;
		for (list<int>::iterator it = lnklistint.iterator(); i < lnklistint.size(); it++, i++)
		{
			cout << *it << endl;
		}

		cout << "LinkedList<int> içeriği tamamen silindi" << endl;
		lnklistint.clear();
		cout << "LinkedList<int>'deki eleman sayısı:" << lnklistint.size() << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl
			 << endl;
		LinkedList<string> lnkliststr;
		cout << "LinkedList<string> oluşturuldu" << endl;
		cout << "LinkedList<string> boş mu? Sonuç:" << lnkliststr.isEmpty() << endl;
		lnkliststr.add("Elma");
		lnkliststr.add("Armut");
		lnkliststr.offer("Karpuz"); //offer fonksiyonu ile ekleme yapıldı.
		lnkliststr.add("Domates");
		lnkliststr.offer("Salatalık");
		lnkliststr.add("Elma");
		lnkliststr.offer("Muz");
		cout << "LinkedList<string>'e Elma,Armut,Karpuz,Domates,Salatalık,Elma,Muz değerleri eklendi" << endl;
		cout << "LinkedList<string>'deki eleman sayısı:" << lnkliststr.size() << endl;
		cout << "LinkedList<string> boş mu? Sonuç:" << lnkliststr.isEmpty() << endl;
		cout << "LinkedList<string> içerisindeki en başta olan eleman getiriliyor.(element fonksiyonu) Listeden silinmiyor Eleman:" << lnkliststr.element();
		cout << " Eleman sayısı:" << lnkliststr.size() << endl;
		cout << "LinkedList<string> içerisindeki en başta olan eleman getiriliyor.(poll fonksiyonu) Listeden siliniyor Eleman:" << lnkliststr.poll();
		cout << " Eleman sayısı:" << lnkliststr.size() << endl;
		cout << "LinkedList<string> içerisinde Patlıcan değerini içeriyormu? Sonuç:" << lnkliststr.contains("Patlıcan") << endl;
		cout << "LinkedList<string> içerisinde Karpuz değerini içeriyormu? Sonuç:" << lnkliststr.contains("Karpuz") << endl;
		cout << "LinkedList<string> içerisinde Salatalık değeri siliniyor? Sonuç:" << lnkliststr.remove("Salatalık");
		cout << " Eleman sayısı:" << lnkliststr.size() << endl;
		cout << "LinkedList<string> deki elemanlar sırası ile yazdırılıyor" << endl;
		i = 0;
		for (list<string>::iterator it = lnkliststr.iterator(); i < lnkliststr.size(); it++, i++)
		{
			cout << *it << endl;
		}

		cout << "LinkedList<string> içeriği tamamen silindi" << endl;
		lnkliststr.clear();
		cout << "LinkedList<string>'deki eleman sayısı:" << lnkliststr.size() << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl
			 << endl;
		HashSet<int> hashsetint;
		cout << "HashSet<int> oluşturuldu" << endl;
		cout << "HashSet<int> boş mu? Sonuç:" << hashsetint.isEmpty() << endl;
		hashsetint.add(50);
		hashsetint.add(20);
		hashsetint.add(10);
		hashsetint.add(40);
		hashsetint.add(30);
		hashsetint.add(50);
		cout << "HashSet<int>'e 50,20,10,40,30,50 değerleri eklendi" << endl;
		cout << "HashSet<int>'deki eleman sayısı:" << hashsetint.size() << "(unique eleman tutuyor)" << endl;
		cout << "HashSet<int> boş mu? Sonuç:" << hashsetint.isEmpty() << endl;
		cout << "HashSet<int> içerisinde 60 değerini içeriyormu? Sonuç:" << hashsetint.contains(60) << endl;
		cout << "HashSet<int> içerisinde 10 değerini içeriyormu? Sonuç:" << hashsetint.contains(10) << endl;
		cout << "HashSet<int> içerisinde 30 değeri siliniyor? Sonuç:" << hashsetint.remove(30);
		cout << " Eleman sayısı:" << hashsetint.size() << endl;
		cout << "HashSet<int> deki elemanlar sıralı olarak yazdırılıyor" << endl;
		i = 0;
		for (set<int>::iterator it = hashsetint.iterator(); i < hashsetint.size(); it++, i++)
		{
			cout << *it << endl;
		}
		cout << "HashSet<int> içeriği tamamen silindi" << endl;
		hashsetint.clear();
		cout << "HashSet<int>'deki eleman sayısı:" << hashsetint.size() << "(unique eleman tutuyor)" << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl
			 << endl;
		HashSet<string> hashsetstr;
		cout << "HashSet<string> oluşturuldu" << endl;
		cout << "HashSet<string> boş mu? Sonuç:" << hashsetstr.isEmpty() << endl;
		hashsetstr.add("Elma");
		hashsetstr.add("Armut");
		hashsetstr.add("Karpuz");
		hashsetstr.add("Domates");
		hashsetstr.add("Salatalık");
		hashsetstr.add("Elma");
		cout << "HashSet<string>'e Elma,Armut,Karpuz,Domates,Salatalık,Elma değerleri eklendi" << endl;
		cout << "HashSet<string>'deki eleman sayısı:" << hashsetstr.size() << endl;
		cout << "HashSet<string> boş mu? Sonuç:" << hashsetstr.isEmpty() << endl;
		cout << "HashSet<string> içerisinde Patlıcan değerini içeriyormu? Sonuç:" << hashsetstr.contains("Patlıcan") << endl;
		cout << "HashSet<string> içerisinde Karpuz değerini içeriyormu? Sonuç:" << hashsetstr.contains("Karpuz") << endl;
		cout << "HashSet<string> içerisinde Salatalık değeri siliniyor? Sonuç:" << hashsetstr.remove("Salatalık");
		cout << " Eleman sayısı:" << hashsetstr.size() << endl;
		cout << "HashSet<string> deki elemanlar sırası ile yazdırılıyor" << endl;
		i = 0;
		for (set<string>::iterator it = hashsetstr.iterator(); i < hashsetstr.size(); it++, i++)
		{
			cout << *it << endl;
		}
		cout << "HashSet<int> içeriği tamamen silindi" << endl;
		hashsetstr.clear();
		cout << "HashSet<int>'deki eleman sayısı:" << hashsetstr.size() << endl
			 << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}