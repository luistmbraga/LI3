package engine;

import java.util.Objects;
import java.time.LocalDate;

/**
 * Classe destinada a designar um Post
 * 
 * @author Grupo 59
 */
public class Post{
	/*Long com o Id do Post*/
	private long id;
	/*String com o nome do autor do Post*/
	private String userid;
	/*LocalDate com a Data do Post*/
	private LocalDate data;

	/**
	 * Construtor padrão de um Post
	 */
	public Post(){
		this.id = -10;
		this.userid = "";
		this.data = LocalDate.now();
	}

	/**
	 * Construtor parametrizado de um Post
	 * @param id
	 * @param userid
	 * @param date
	 */
	public Post(long id, String userid, LocalDate date){
		this.id = id;
		this.userid = userid;
		this.data = date;
	}

	/**
	 * Construtor por cópia de uma post
	 * @param p
	 */
	public Post(Post p){
		this.id = p.getID();
		this.userid = p.getUserID();
		this.data = p.getData();
	}

	/**
	 * Devolve o Id de um Post
	 * @return
	 */
	public long getID(){
		return this.id;
	}

	/**
	 * Define Id de um Post
	 * @return
	 */
	public void setID(long id){
		this.id = id;
	}

	/**
	 * Devolve a Id do autor do Post
	 * @return
	 */
	public String getUserID(){
		return this.userid;
	}

	/**
	 * Define o Id do autor do Post
	 * @param s
	 */
	public void setUserID(String s){
		this.userid = s;
	}

	/**
	 * Devolve a Data de um Post
	 * @return LocalDate
	 */
	public LocalDate getData(){
		return this.data;
	}

	/**
	 * Define a data de um Post
	 * @param d
	 */
	public void setData(LocalDate d){
		this.data = d;
	}

	/**
	 * Verifica se um Post é uma Pergunta
	 * @return boolean
	 */
	public boolean isPergunta(){
		return this.getClass().getSimpleName().equals("Pergunta");
	}

	/**
	 * Verifica se um Post está dentro das LocalDate dadas
	 * @param begin
	 * @param end
	 * @return boolean
	 */
	public boolean isIntervalo(LocalDate begin, LocalDate end){
		return ((this.data.isAfter(begin) && this.data.isBefore(end)) || (this.data.equals(end) || this.data.equals(begin)));
	}

	/**
	 * Devolve uma cópia de um Post
	 * @return 
	 */
	public Post clone(){
		return new Post(this);
	}

	/**
	 * Método equals da classe Post  
	 * @param obj
	 * @return boolean
	 */
	public boolean equals(Object o){
		if (o == this) return true;
		if (this.getClass() != o.getClass() || o == null) return false;

		Post p = (Post) o;

		return (this.id == p.getID() && this.userid.equals(p.getUserID()) && this.data.equals(p.getData()));
	}

	/**
	 * Constrói e devolve uma string da class Post
	 * @return
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("\n ID: " + this.id);
		sb.append("\n UserID:" + this.userid);
		sb.append("\n Data:" + this.data);

		return sb.toString();
	}

}
