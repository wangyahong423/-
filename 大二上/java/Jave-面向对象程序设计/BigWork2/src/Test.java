
import java.io.*;
import java.util.Scanner;

public class Test {
	private static boolean tr=true;
	public static void main(String[] args){
		while(tr){
		System.out.println("1.新增会员");
		System.out.println("2.新增商品");
		System.out.println("3.借书或DVD");
		System.out.println("4.还书或DVD");
		System.out.println("5.显示所有会员信息");
		System.out.println("6.显示所有商品信息");
		System.out.println("7.修改会员信息");
		System.out.println("8.退出程序");
		System.out.println("请选择要进行的操作！");
		Scanner input=new Scanner(System.in);
		int i=input.nextInt();
		switch(i){
		
		case 1:{
			Administration m = new Administration();
			Scanner a = new Scanner(System.in);
			System.out.println("请输入要保存的会员的数量：");
			int num = a.nextInt();
			m.InitializationVIP(num);
			m.addVIP();
			m.writeVIP();

			break;
		}
		case 2:{
			System.out.println("1.添加图书！");
			System.out.println("2.添加DVD！");
			
			int j=input.nextInt();
			switch(j){
			case 1:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("请输入要添加的图书数量：");
				int num = a.nextInt();
				m.InitializationBook(num);
				m.addBook();
				m.writeBook();
				break;
				
				
				
				
			}
			case 2:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("请输入要添加的DVD数量：");
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
			System.out.println("1.借书！");
			System.out.println("2.借DVD！");
			int j=input.nextInt();
			switch(j){
			case 1:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("请输入要借阅的图书名称：");
				String name = a.next();
				m.borrowBook(name);
				break;
				
			}
			case 2:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("请输入要借阅的DVD名称：");
				String name = a.next();
				m.borrowDVD(name);
				break;
				
			}
			}
			break;

		}
		case 4:{
			System.out.println("1.还书！");
			System.out.println("2.还DVD！");
			int j=input.nextInt();
			switch(j){
			case 1:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("请输入要归还的图书名称：");
				String name = a.next();
				m.returnBook(name);
				break;
			}
			case 2:{
				Administration m = new Administration();
				Scanner a = new Scanner(System.in);
				System.out.println("请输入要借阅的DVD名称：");
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
			System.out.println("打印所有商品信息！");
			Administration m = new Administration();
			m.printing_AllBook();
			m.printing_AllDVD();
			break;
		}
		case 7:{
			Administration m = new Administration();
			System.out.println("请输入姓名：");
			Scanner a = new Scanner(System.in);
			String name=a.next();
			System.out.println("请输入要修改的姓名");
			String gainame=a.next();
			System.out.println("请输入要修改的编号");
			String id=a.next();
			System.out.println("请输入要修改的电话");
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
