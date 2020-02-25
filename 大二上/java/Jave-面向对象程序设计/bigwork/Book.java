package bigwork;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Book extends Produce {
	private String author;
	private String ISBN;
	public String getAuthor() {
		return author;
	}
	public void setAuthor(String author) {
		this.author = author;
	}
	public String getISBN() {
		return ISBN;
	}
	public void setISBN(String iSBN) {
		ISBN = iSBN;
	}
	public void add(Produce p) {
		if(p instanceof Book) {
			Book b=(Book) p;
			System.out.println("请输入图书信息：");
			System.out.println("编号");
			b.number=input.nextLine();
			System.out.println("名称");
			b.name=input.nextLine();
			System.out.println("数量");
			b.quantity=input.nextInt();
			String huiche0=input.nextLine();
			System.out.println("作者");
			b.author=input.nextLine();
			System.out.println("ISBN号");
			b.ISBN=input.nextLine();
			try {
				FileReader fileReader =new FileReader("F:\\produce.txt");
				Writer writer=new FileWriter("F:\\produce.txt",true);
				writer.write(this.toString()+"\r\n");
				writer.close();
				this.tag=1;
				System.out.println("图书添加成功");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "编号："+number+"名称："+name+"数量："+quantity+"作者："+author+"ISBN号："+ISBN;
	}
}
