package engine;

import engine.Post;

import java.util.Objects;
import java.util.List;
import java.util.ArrayList;
import java.time.LocalDate;

/**
 * Classe destinada a designar uma Pergunta
 *
 * @author Grupo 59
 */
public class Pergunta extends Post{
	/*String com o titulo da Pergunta*/
	private String titulo;
	/*String com as tags da Pergunta*/
	private String tags;

	/**
	 * Construtor padrão de uma Pergunta
	 */
	public Pergunta(){
		super();
		this.titulo = "";
		this.tags = "";
	} 

	/**
	 * Construtor de parametrizado de uma Pergunta
	 * @param id
	 * @param userid
	 * @param data
	 * @param titulo
	 * @param tags
	 */
	public Pergunta(long id, String userid, LocalDate data, String titulo, String tags){
		super(id, userid, data);
		this.titulo = titulo;
		this.tags = tags;
	}

	/**
	 * Construtor por cópia de uma Pergunta
	 * @param p
	 */
	public Pergunta(Pergunta p){
		super(p);
		this.titulo = p.getTitulo();
		this.tags = p.getTags();
	}

	/**
	 * Devolve o titulo de uma Pergunta
	 * @return
	 */
	public String getTitulo(){
		return this.titulo;
	}

	/**
	 * Define o titulo de uma Pergunta
	 * @param t
	 */
	public void setTitulo(String t){
		this.titulo = t;
	}

	/**
	 * Devolve as tags de uma Pergunta
	 * @return String
	 */
	public String getTags(){
		return this.tags;
	}

	/**
	 * Define as tags de uma Pergunta
	 * @param tags
	 */
	public void setTags(String tags){
		this.tags = tags;
	}

	/**
	 * Método equals de uma Pergunta
	 * @param o
	 * @return boolean
	 */
	public boolean equals(Object o){
		if (this == o) return true;
		if(o == null || this.getClass() != o.getClass()) return false;

		Pergunta p = (Pergunta) o;

		return (super.equals(p) && this.titulo.equals(p.getTitulo()) && this.tags.equals(p.getTags()));

	}

	/**
	 * Devolve uma cópia de uma Pergunta
	 * @return
	 */
	public Pergunta clone(){
		return new Pergunta(this);
	}


	/**
	 * Constrói e devolve uma string da class Pergunta
	 * @return
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString());
		sb.append("\n Titulo da pergunta: " + this.titulo);
		sb.append("\n Tags: " + this.tags);

		return sb.toString();
	}
}
