
public class VIP {
	private String id;
	private String name;
	private String phone;
	
//	public VIP(String id,String name,String phone){
//		this.id=id;
//		this.name=name;
//		this.phone=phone;
//	}
	public String getID(){
		return id;
	}
	public void setID(String str){
		this.id=str;
	}
	public String getName(){
		return name;
	}
	public void setName(String str){
		this.name=str;
	}
	public String getPhone(){
		return phone;
	}
	public void setPhone(String str){
		this.phone=str;
	}
	public String toString() {
		return "VIP [±àºÅ=" + id + ", ÐÕÃû=" + name + ", µç»°=" + phone+ "]";
	}

}
