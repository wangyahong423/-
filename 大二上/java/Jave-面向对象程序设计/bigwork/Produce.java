package bigwork;

import java.util.Scanner;

public class Produce {
	Scanner input = new Scanner(System.in);
	protected String number;
	protected String name;
	protected int quantity;
	protected int tag;
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getQuantity() {
		return quantity;
	}
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	public void add(Produce p) {
		System.out.println("请输入编号，名称，数量");
		p.number=input.nextLine();
		String huiche=input.nextLine();
		p.name=input.nextLine();
		p.quantity=input.nextInt();
		System.out.println("添加成功");
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return this.getName()+this.getNumber()+this.getQuantity();
	}
	public void find(String str) {
		if(this.name.equals(str)||this.number.equals(str)){
			if(this instanceof Book) {
				Book b = (Book) this;
				System.out.println(b.toString());
			}else {
				if(this instanceof DVD) {
					DVD d = (DVD) this;
					System.out.println(d.toString());
				}
			}
		}
	}
	public void display() {
		if(this instanceof Book) {
			Book b=(Book) this;
			System.out.println(this.toString());
		}else {
			Produce p=(Produce) this;
			System.out.println(this.toString());
		}
			
	}
}
