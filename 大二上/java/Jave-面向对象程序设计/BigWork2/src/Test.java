
import java.io.*;
import java.util.Scanner;

public class Test {
	private static boolean tr=true;
	public static void main(String[] args){
		while(tr){
		System.out.println("1.������Ա");
		System.out.println("2.������Ʒ");
		System.out.println("3.�����DVD");
		System.out.println("4.�����DVD");
		System.out.println("5.��ʾ���л�Ա��Ϣ");
		System.out.println("6.��ʾ������Ʒ��Ϣ");
		System.out.println("7.�޸Ļ�Ա��Ϣ");
		System.out.println("8.�˳�����");
		System.out.println("��ѡ��Ҫ���еĲ�����");
		Scanner input=new Scanner(System.in);
		int i=input.nextInt();
		switch(i){
		
		case 1:{
			Administration m = new Administration();
			Scanner a = new Scanner(System.in);
			System.out.println("������Ҫ����Ļ�Ա��������");
			int num = a.nextInt();
			m.InitializationVIP(num);
			m.addVIP();
			m.writeVIP();

			break;
		}
		case 2:{
			System.out.println("1.���ͼ�飡");
			System.out.println("2.���DVD��");
			
			int j=input.nextInt();
			switch(j){
			case 1:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("������Ҫ��ӵ�ͼ��������");
				int num = a.nextInt();
				m.InitializationBook(num);
				m.addBook();
				m.writeBook();
				break;
				
				
				
				
			}
			case 2:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("������Ҫ��ӵ�DVD������");
				int num = a.nextInt();
				m.InitializationDVD(num);
				m.addDVD();
				m.writeDVD();
				break;
				
			}
			}
			break;
			
		}
		case 3:{
			System.out.println("1.���飡");
			System.out.println("2.��DVD��");
			int j=input.nextInt();
			switch(j){
			case 1:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("������Ҫ���ĵ�ͼ�����ƣ�");
				String name = a.next();
				m.borrowBook(name);
				break;
				
			}
			case 2:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("������Ҫ���ĵ�DVD���ƣ�");
				String name = a.next();
				m.borrowDVD(name);
				break;
				
			}
			}
			break;

		}
		case 4:{
			System.out.println("1.���飡");
			System.out.println("2.��DVD��");
			int j=input.nextInt();
			switch(j){
			case 1:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("������Ҫ�黹��ͼ�����ƣ�");
				String name = a.next();
				m.returnBook(name);
				break;
			}
			case 2:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("������Ҫ���ĵ�DVD���ƣ�");
				String name = a.next();
				m.borrowDVD(name);
				break;
				
			}
			}
			break;
		
		}
		case 5:{
			Administration m = new Administration();
			Scanner a = new Scanner(System.in);
			m.printing_AllVIP();
			break;
		}
		case 6:{
			System.out.println("��ӡ������Ʒ��Ϣ��");
			Administration m = new Administration();
			m.printing_AllBook();
			m.printing_AllDVD();
			break;
		}
		case 7:{
			Administration m = new Administration();
			System.out.println("������������");
			Scanner a = new Scanner(System.in);
			String name=a.next();
			System.out.println("������Ҫ�޸ĵ�����");
			String gainame=a.next();
			System.out.println("������Ҫ�޸ĵı��");
			String id=a.next();
			System.out.println("������Ҫ�޸ĵĵ绰");
			String phone=a.next();
			m.modify(name,gainame,id,phone);
			break;
		}
		case 8:{
			tr=false;
			break;
			
		}
		}
		}
	}

}
