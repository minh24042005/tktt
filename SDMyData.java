import java.util.*;
public class SDMyData {
	public static void main(String[] args) {
		MyData d1 = new MyData();
		System.out.println("Nhap gia tri ngay");
		d1.nhap();
		d1.hienthi();
		System.out.println();
		Scanner kb = new Scanner(System.in);
		System.out.print("Nhap n: ");
		int n = kb.nextInt();
		d1.congNgay(n).hienthi();
		kb.close();
}
}
