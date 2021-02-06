/**
 * main.java
 * 
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since 2019
 */
public class main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {

			System.out.println("Class Test\n");
			System.out
					.println("-------------------------------------------------------------\n");
			ArrayList<Integer> arrlistint = new ArrayList<Integer>();
			System.out.println("ArrayList<int> oluşturuldu");
			System.out.println("ArrayList<int> boş mu? Sonuç:"
					+ arrlistint.isEmpty());
			arrlistint.add(50);
			arrlistint.add(20);
			arrlistint.add(10);
			arrlistint.add(40);
			arrlistint.add(30);
			arrlistint.add(50);
			System.out
					.println("ArrayList<int>'e 50,20,10,40,30,50 değerleri eklendi");
			System.out.println("ArrayList<int>'deki eleman sayısı:"
					+ arrlistint.size());
			System.out.println("ArrayList<int> boş mu? Sonuç:"
					+ arrlistint.isEmpty());
			System.out
					.println("ArrayList<int> içerisinde 60 değerini içeriyormu? Sonuç:"
							+ arrlistint.contains(60));
			System.out
					.println("ArrayList<int> içerisinde 10 değerini içeriyormu? Sonuç:"
							+ arrlistint.contains(10));
			System.out
					.print("ArrayList<int> içerisinde 30 değeri siliniyor? Sonuç:"
							+ arrlistint.remove(30));
			System.out.println(" Eleman sayısı:" + arrlistint.size());
			System.out
					.println("ArrayList<int> deki elemanlar sırası ile yazdırılıyor");

			for (int i = 0; i < arrlistint.size(); i++) {
				System.out.println(arrlistint.get(i));
			}

			System.out.println("ArrayList<int> içeriği tamamen silindi");
			arrlistint.clear();
			System.out.println("ArrayList<int>'deki eleman sayısı:"
					+ arrlistint.size() + "\n");
			System.out
					.println("-------------------------------------------------------------\n");
			ArrayList<String> arrliststr = new ArrayList<String>();
			System.out.println("ArrayList<string> oluşturuldu");
			System.out.println("ArrayList<string> boş mu? Sonuç:"
					+ arrliststr.isEmpty());
			arrliststr.add("Elma");
			arrliststr.add("Armut");
			arrliststr.add("Karpuz");
			arrliststr.add("Domates");
			arrliststr.add("Salatalık");
			arrliststr.add("Elma");
			System.out
					.println("ArrayList<string>'e Elma,Armut,Karpuz,Domates,Salatalık,Elma değerleri eklendi");
			System.out.println("ArrayList<string>'deki eleman sayısı:"
					+ arrliststr.size());
			System.out.println("ArrayList<string> boş mu? Sonuç:"
					+ arrliststr.isEmpty());
			System.out
					.println("ArrayList<string> içerisinde Patlıcan değerini içeriyormu? Sonuç:"
							+ arrliststr.contains("Patlıcan"));
			System.out
					.println("ArrayList<string> içerisinde Karpuz değerini içeriyormu? Sonuç:"
							+ arrliststr.contains("Karpuz"));
			System.out
					.print("ArrayList<string> içerisinde Salatalık değeri siliniyor? Sonuç:"
							+ arrliststr.remove("Salatalık"));
			System.out.println(" Eleman sayısı:" + arrliststr.size());
			System.out
					.println("ArrayList<string> deki elemanlar sırası ile yazdırılıyor");

			for (int i = 0; i < arrliststr.size(); i++) {
				System.out.println(arrliststr.get(i));
			}

			System.out.println("ArrayList<int> içeriği tamamen silindi");
			arrliststr.clear();
			System.out.println("ArrayList<int>'deki eleman sayısı:"
					+ arrliststr.size() + "\n");
			System.out
					.println("-------------------------------------------------------------\n");
			LinkedList<Integer> lnklistint = new LinkedList<Integer>();
			System.out.println("LinkedList<int> oluşturuldu");
			System.out.println("LinkedList<int> boş mu? Sonuç:"
					+ lnklistint.isEmpty());
			lnklistint.add(20);
			lnklistint.add(50);
			lnklistint.offer(10); // offer fonksiyonu ile ekleme yapıldı.
			lnklistint.add(40);
			lnklistint.offer(30);
			lnklistint.add(50);
			lnklistint.offer(80);
			System.out
					.println("LinkedList<int>'e 20,50,10,40,30,50,80 değerleri eklendi");
			System.out.println("LinkedList<int>'deki eleman sayısı:"
					+ lnklistint.size());
			System.out.println("LinkedList<int> boş mu? Sonuç:"
					+ lnklistint.isEmpty());
			System.out
					.println("LinkedList<int> içerisindeki en sonda olan eleman getiriliyor.(element fonksiyonu) Listeden silinmiyor Eleman:"
							+ lnklistint.element());
			System.out.println(" Eleman sayısı:" + lnklistint.size());
			System.out
					.println("LinkedList<int> içerisindeki en sonda olan eleman getiriliyor.(poll fonksiyonu) Listeden siliniyor Eleman:"
							+ lnklistint.poll());
			System.out.println(" Eleman sayısı:" + lnklistint.size());
			System.out
					.println("LinkedList<int> içerisinde 60 değerini içeriyormu? Sonuç:"
							+ lnklistint.contains(60));
			System.out
					.println("LinkedList<int> içerisinde 10 değerini içeriyormu? Sonuç:"
							+ lnklistint.contains(10));
			System.out
					.print("LinkedList<int> içerisinde 30 değeri siliniyor? Sonuç:"
							+ lnklistint.remove(30));
			System.out.println(" Eleman sayısı:" + lnklistint.size());
			System.out
					.println("LinkedList<int> deki elemanlar sırası ile yazdırılıyor");

			for (int i = 0; i < lnklistint.size(); i++) {
				System.out.println(lnklistint.get(i));
			}

			System.out.println("LinkedList<int> içeriği tamamen silindi");
			lnklistint.clear();
			System.out.println("LinkedList<int>'deki eleman sayısı:"
					+ lnklistint.size() + "\n");
			System.out
					.println("-------------------------------------------------------------\n");
			LinkedList<String> lnkliststr = new LinkedList<String>();
			System.out.println("LinkedList<string> oluşturuldu");
			System.out.println("LinkedList<string> boş mu? Sonuç:"
					+ lnkliststr.isEmpty());
			lnkliststr.add("Armut");
			lnkliststr.add("Elma");
			lnkliststr.offer("Karpuz"); // offer fonksiyonu ile ekleme yapıldı.
			lnkliststr.add("Domates");
			lnkliststr.offer("Salatalık");
			lnkliststr.add("Elma");
			lnkliststr.offer("Muz");
			System.out
					.println("LinkedList<string>'e Armut,Elma,Karpuz,Domates,Salatalık,Elma,Muz değerleri eklendi");
			System.out.println("LinkedList<string>'deki eleman sayısı:"
					+ lnkliststr.size());
			System.out.println("LinkedList<string> boş mu? Sonuç:"
					+ lnkliststr.isEmpty());
			System.out
					.print("LinkedList<string> içerisindeki en sonda olan eleman getiriliyor.(element fonksiyonu) Listeden silinmiyor Eleman:"
							+ lnkliststr.element());
			System.out.println(" Eleman sayısı:" + lnkliststr.size());
			System.out
					.print("LinkedList<string> içerisindeki en sonda olan eleman getiriliyor.(poll fonksiyonu) Listeden siliniyor Eleman:"
							+ lnkliststr.poll());
			System.out.println(" Eleman sayısı:" + lnkliststr.size());
			System.out
					.println("LinkedList<string> içerisinde Patlıcan değerini içeriyormu? Sonuç:"
							+ lnkliststr.contains("Patlıcan"));
			System.out
					.println("LinkedList<string> içerisinde Karpuz değerini içeriyormu? Sonuç:"
							+ lnkliststr.contains("Karpuz"));
			System.out
					.print("LinkedList<string> içerisinde Salatalık değeri siliniyor? Sonuç:"
							+ lnkliststr.remove("Salatalık"));
			System.out.println(" Eleman sayısı:" + lnkliststr.size());
			System.out
					.println("LinkedList<string> deki elemanlar sırası ile yazdırılıyor");

			for (int i = 0; i < lnkliststr.size(); i++) {
				System.out.println(lnkliststr.get(i));
			}

			System.out.println("LinkedList<string> içeriği tamamen silindi");
			lnkliststr.clear();
			System.out.println("LinkedList<string>'deki eleman sayısı:"
					+ lnkliststr.size() + "\n");
			System.out
					.println("-------------------------------------------------------------\n");

			HashSet<Integer> hashsetint = new HashSet<Integer>();
			System.out.println("HashSet<int> oluşturuldu");
			System.out.println("HashSet<int> boş mu? Sonuç:"
					+ hashsetint.isEmpty());
			hashsetint.add(50);
			hashsetint.add(20);
			hashsetint.add(10);
			hashsetint.add(40);
			hashsetint.add(30);
			hashsetint.add(50);
			System.out
					.println("HashSet<int>'e 50,20,10,40,30,50 değerleri eklendi");
			System.out.println("HashSet<int>'deki eleman sayısı:"
					+ hashsetint.size() + "(unique eleman tutuyor)");
			System.out.println("HashSet<int> boş mu? Sonuç:"
					+ hashsetint.isEmpty());
			System.out
					.println("HashSet<int> içerisinde 60 değerini içeriyormu? Sonuç:"
							+ hashsetint.contains(60));
			System.out
					.println("HashSet<int> içerisinde 10 değerini içeriyormu? Sonuç:"
							+ hashsetint.contains(10));
			System.out
					.print("HashSet<int> içerisinde 30 değeri siliniyor? Sonuç:"
							+ hashsetint.remove(30));
			System.out.println(" Eleman sayısı:" + hashsetint.size());
			System.out
					.println("HashSet<int> deki elemanlar sıralı olarak yazdırılıyor");

			for (int i = 0; i < hashsetint.size(); i++) {
				System.out.println(hashsetint.get(i));
			}

			System.out.println("HashSet<int> içeriği tamamen silindi");
			hashsetint.clear();
			System.out.println("HashSet<int>'deki eleman sayısı:"
					+ hashsetint.size() + "(unique eleman tutuyor)\n");
			System.out
					.println("-------------------------------------------------------------\n");
			HashSet<String> hashsetstr = new HashSet<String>();
			System.out.println("HashSet<string> oluşturuldu");
			System.out.println("HashSet<string> boş mu? Sonuç:"
					+ hashsetstr.isEmpty());
			hashsetstr.add("Elma");
			hashsetstr.add("Armut");
			hashsetstr.add("Karpuz");
			hashsetstr.add("Domates");
			hashsetstr.add("Salatalık");
			hashsetstr.add("Elma");
			System.out
					.println("HashSet<string>'e Elma,Armut,Karpuz,Domates,Salatalık,Elma değerleri eklendi");
			System.out.println("HashSet<string>'deki eleman sayısı:"
					+ hashsetstr.size());
			System.out.println("HashSet<string> boş mu? Sonuç:"
					+ hashsetstr.isEmpty());
			System.out
					.println("HashSet<string> içerisinde Patlıcan değerini içeriyormu? Sonuç:"
							+ hashsetstr.contains("Patlıcan"));
			System.out
					.println("HashSet<string> içerisinde Karpuz değerini içeriyormu? Sonuç:"
							+ hashsetstr.contains("Karpuz"));
			System.out
					.print("HashSet<string> içerisinde Salatalık değeri siliniyor? Sonuç:"
							+ hashsetstr.remove("Salatalık"));
			System.out.println(" Eleman sayısı:" + hashsetstr.size());
			System.out
					.println("HashSet<string> deki elemanlar sırası ile yazdırılıyor");

			for (int i = 0; i < hashsetstr.size(); i++) {
				System.out.println(hashsetstr.get(i));
			}

			System.out.println("HashSet<int> içeriği tamamen silindi");
			hashsetstr.clear();
			System.out.println("HashSet<int>'deki eleman sayısı:"
					+ hashsetstr.size() + "\n");
			System.out
					.println("-------------------------------------------------------------");
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

	}

}
