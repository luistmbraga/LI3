package engine;

import engine.Post;

import java.util.Objects;
import java.time.LocalDate;

/**
 * Classe destinada a designar uma Resposta
 * 
 * @author Grupo 59
 */
public class Resposta extends Post{
	/*Id da Pergunta a que a Resposta responde*/
	private long parentid;
	/*Score da Resposta*/
	private long scr;
	/*Long com o número de comentários à Resposta*/
	private long ncom;

	/**
	 * Construtor padrão de uma Resposta
	 */
	public Resposta(){
		super();
		this.parentid = -1;
		this.scr = 0;
		this.ncom = ncom;
	}

	/**
	 * Construtor parametrizado de uma Resposta
	 * @param id
	 * @param userid
	 * @param data
	 * @param parentid
	 * @param scr
	 * @param ncom
	 */
	public Resposta(long id, String userid, LocalDate data, long parentid, long scr, long ncom){
		super(id, userid, data);
		this.parentid = parentid;
		this.scr = scr;
		this.ncom = ncom;
	}

	/**
	 * Construtor por cópia de uma Resposta
	 * @param r
	 */
	public Resposta(Resposta r){
		super(r);
		this.parentid = r.getParentID();
		this.scr = r.getScr();
		this.ncom = r.getNcom();
	}

	/**
	 * Devolve o Id da Pergunta a que a Resposta responde
	 * @return
	 */
	public long getParentID(){
		return this.parentid;
	}

	/**
	 * Define o Id da Pergunta a que a Resposta responde
	 * @param parentid
	 */
	public void setParentID(long parentid){
		this.parentid = parentid;
	}

	/**
	 * Devolve o score de uma Resposta
	 * @return long
	 */
	public long getScr(){
		return this.scr;
	}

	/**
	 * Define o score uma Resposta
	 * @param scr
	 */
	public void setScr(long scr){
		this.scr = scr;
	}

	/**
	 * Devolve o número de comentários a uma Resposta
	 * @return
	 */
	public long getNcom(){
		return this.ncom;
	}

	/**
	 * Define o número de comentários a uma Resposta
	 * @param ncom
	 */
	public void setNcom(long ncom){
		this.ncom = ncom;
	}

	/**
	 * Devolve o valor calculado para a decisão da melhor Resposta
	 * @param rep
	 * @return
	 */
	public double calculoMedia(long rep){ 
		return (0.65*this.scr + rep*0.25 + this.ncom*0.1);
	}

	/**
	 * Devolve uma cópia de uma Resposta
	 * @return
	 */
	public Resposta clone(){
		return new Resposta(this);
	}

	/**
	 * Método equals de uma Resposta
	 * @param o
	 * @return boolean
	 */
	public boolean equals(Object o){
		if (this == o) return true;
		if(this.getClass() != o.getClass() || o == null) return false;

		Resposta r = (Resposta) o;

		return(super.equals(r) && this.parentid == r.getParentID() && this.scr == r.getScr() && this.ncom == r.getNcom());
	}

	/**
	 * Constrói e devolve uma string da class Resposta
	 * @return
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString());
		sb.append("\n ParentID: " + this.parentid);
		sb.append("\n Score: " + this.scr);
		sb.append("\n Número de comentários: " + this.ncom);

		return sb.toString();
	}
}
