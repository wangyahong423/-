
public class Book extends Commodity {
	private String writer;
	private String ISBN;

//	public Book(String commodityName, String id, double number, String author, String iSBN) {
//		super(commodityName, id, number);
//		this.author = author;
//		this.ISBN = iSBN;
//	}

	public String getWriter() {
		return writer;
	}
	public void setWriter(String str){
		this.writer=str;
	}

	public String getISBN() {
		return ISBN;
	}
	public void setISBN(String str){
		this.ISBN=str;
	}

	public String toString() {
		return "Book [ͼ�����ƣ�" + getCommodityName() + ", ͼ���ţ�" + getId()+", ������" + getNumber()  + ", ���ߣ�" + writer + ", ISBN�ţ�" + ISBN +"]";
	}

}
