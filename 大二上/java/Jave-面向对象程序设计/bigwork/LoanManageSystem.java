package bigwork;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
public class LoanManageSystem {
	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		int mNumMax=1000;
		int pNumMax=1000;
		int lNumMax=1000;
		LoanRecord record=new LoanRecord();
		Member [] mm = new Member[mNumMax];
		Produce [] pp =new Produce[pNumMax];
		LoanRecord [] ll=new LoanRecord[lNumMax];
		int mNumNow=0;
		int pNumNow=0;
		int lNumNow=0;
		int num=0;
		do {
			System.out.println("1.新增会员");
			System.out.println("2.新增商品");
			System.out.println("3.借书或DVD");
			System.out.println("4.还书或DVD");
			System.out.println("5.显示所有会员信息");
			System.out.println("6.显示所有商品信息");
			System.out.println("7.退出程序");
			int choose =input.nextInt();
			String huiche=input.nextLine();
			switch (choose) {
			case 1:
				mm[mNumNow]=new Member();
				mm[mNumNow].add();
				mNumNow++;
				lNumNow++;
				break;
			case 2:
				System.out.println("请选择增加商品的种类");
				System.out.println("a:Book");
				System.out.println("b:DVD");
				String kinds=input.nextLine();
				if (kinds.equals("a")) {
					pp[pNumNow]=new Book();
					pp[pNumNow].add(pp[pNumNow]);
					pNumNow++;
				}else {
					pp[pNumNow]=new DVD();
					pp[pNumNow].add(pp[pNumNow]);
					pp[pNumNow].tag=1;
					pNumNow++;
				}
				break;
			case 3:
				int i,j;
				System.out.println("请输入你想借阅的图书或DVD的名称或编号");
				String str=input.nextLine();
				System.out.println("情输入你的名字");
				String name=input.nextLine();
				for(i=0;i<pNumNow;i++) {
					pp[i].find(str);
					break;
				}
				for(j=0;j<mNumNow;j++) {
					mm[j].find(name);
					break;
				}
				
				if(pp[i]==null) {
					System.out.println("没有这本书");
					break;
				}
				else if(pp[i].tag==1) {
					pp[i].tag--;
					ll[lNumNow]=new LoanRecord();
					ll[lNumNow].borrowRecord(mm[j], pp[i]);
					System.out.println("借阅成功，看完后请及时归还");
				}else {
					System.out.println("该书已被借阅");
					break;
				}
				pNumNow--;
				lNumNow++;
				break;
			case 4:
				int a;
				System.out.println("请输入你的名字");
				String name1=input.nextLine();
				for(a=0;a<mNumNow;a++) {
					if(mm[a].find(name1));
						break;
				}
				System.out.println("请输入你想归还图书或DVD的名称或编号");
				str =input.nextLine();
				for(i=0;i<pNumNow;i++) {
					pp[i].find(str);
					break;
				}
				if(pp[i]==null) {
					System.out.println("这本书不是我们图书馆的");
					break;
				}else if(pp[i].tag==0) {
					pp[pNumNow].tag++;
					ll[lNumNow].returnRecord(mm[a],pp[i]);
					System.out.println("归还成功");					
				}else {
					System.out.println("该书没有被借出");
					break;
				}
				ll[lNumNow].returnRecord(mm[a],pp[i]);
				pNumNow++;
				lNumNow++;
				break;
			case 5:
				for(int b=0;b<=mNumNow;b++) {
					mm[b].display(mm[b]);
				}
				break;
			case 6:
				for(int b=0;b<=pNumNow;b++) {
					pp[b].display();
				}
				break;
			case 7:
				num=7;
			}
		} while (num==0);
	}
}
