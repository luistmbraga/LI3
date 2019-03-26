package engine;

import java.util.Objects;

/**
 * Classe destinada a designar uma Tag
 * 
 * @author Grupo 59
 */
public class Tag{
	/*String da Tag correspondente*/
	private String tagName; 
	/*Long com o Id da Tag*/
	private long tagId;

	/**
	 * Construtor padrão de uma Tag
	 */
	public Tag(){
		this.tagName = "";
		this.tagId = -2;
	}

	/**
	 * Construtor parametrizado de uma Tag
	 * @param tagName
	 * @param id
	 */
	public Tag(String tagName, long id){
		this.tagName = tagName;
		this.tagId = id;
	}

	/**
	 * Construtor por cópia de uma Tag
	 * @param tag
	 */
	public Tag(Tag tag){
		this.tagName = tag.getTagName();
		this.tagId = tag.getTagId();
	}

	/**
	 * Devolve a String corresponde à Tag
	 * @return
	 */
	public String getTagName(){
		return this.tagName;		
	}

	/**
	 * Define a String correspondente à Tag
	 * @param tagName
	 */
	public void setTagName(String tagName){
		this.tagName = tagName;
	}

	/**
	 * Devolve o Id da Tag
	 * @return
	 */
	public long getTagId(){ 
		return this.tagId;
	} 

	/**
	 * Define o Id da Tag
	 * @param id
	 */
	public void setTagId(long id){ 
		this.tagId = id;
	}
	
	/**
	 * Devolve uma cópia de uma Tag
	 * @return
	 */
	public Tag clone(){
		return new Tag(this);
	}

	/**
	 * Método equals de uma Tag
	 * @param o
	 * @return boolean
	 */
	public boolean equals(Object o){
		if(this == o) return true;
		if(this == null || this.getClass() != o.getClass()) return false;

		Tag tag = (Tag) o;

		return (this.tagName == tag.getTagName() && this.tagId == tag.getTagId());
	}

	/**
	 * Constrói e devolve uma string da class Tag
	 * @return
	 */
	public String toString(){
		return "<" + this.tagName + ", " + this.tagId + ">";
	}
}
