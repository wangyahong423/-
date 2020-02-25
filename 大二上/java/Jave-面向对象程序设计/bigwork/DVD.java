package bigwork;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class DVD extends Produce{
	private String ISRC;

	public String getISRC() {
		return ISRC;
	}

	public void setISRC(String iSRC) {
		ISRC = iSRC;
	}
	public void add(Produce p) {
		if(p instanceof DVD) {
			DVD d= (DVD) p;
			System.out.println("请输入DVD信息：");
			System.out.println("编号");
			d.number=input.nextLine();
			System.out.println("名称");
			d.name=input.nextLine();
			System.out.println("数量");
			d.quantity=input.nextInt();
			String huiche0=input.nextLine();
			System.out.println("ISRC号");
			d.ISRC=input.nextLine();
			try {
				FileReader fileReader =new FileReader("F:\\produce.txt");
				Writer writer=new FileWriter("F:\\produce.txt",true);
				writer.write(this.toString()+"\r\n");
				writer.close();
				System.out.println("DVD添加成功");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "编号："+number+"名称："+name+"数量："+quantity+"ISRC号："+ISRC;
	}
}
