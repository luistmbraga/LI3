package engine;   

import java.util.Objects;  
import java.time.LocalDate;
import java.util.List;


/**
 * Classe destinada a designar uma Data 
 *
 * @author Grupo 59
 */
public class Data{ 

	/*Long com id do Post em questão*/
	private long id; 
	/*LocalDate com a data do Post em questão*/
	private LocalDate data; 

	/**
	 * Construtor padrão de uma Data
	 */
	public Data(){ 
		this.id = 0; 
		this.data = LocalDate.now();
	}

	/**
	 * Construtor parametrizado
	 * @param id
	 * @param date
	 */
	public Data(Long id, LocalDate date){ 
		this.id = id; 
		this.data = date;
	}

	/**
	 * Construtor parametrizado
	 * @param d
	 */
	public Data(Data d){ 
		this.id = d.getId(); 
		this.data = d.getData(); 
	}

	/**
	 * Devolve o Id da Data
	 * @return
	 */
	public long getId(){ 
		return this.id;
	}

	/**
	 * Define o Id de uma Data
	 * @param id
	 */
	public void setId(long id){ 
		this.id = id;
	}

	/**
	 * Devolve o LocalDate data de um objecto Data
	 * @return 
	 */
	public LocalDate getData(){ 
		return this.data;
	}

	/**
	 * Define a LocalaDate data de um objecto Data
	 * @param date
	 */
	public void setData(LocalDate date){ 
		this.data = date;
	}

	/**
	 * Gera a chave a ser utilizada na tabela de Hash
	 * @return int
	 */
	public int hashCode(){
		int hash = 7;
		long idr = this.id;
		hash += 37*hash + (int) (idr ^ (idr >>> 32));
		hash += 37*hash + this.data.hashCode();

		return hash;
	}

	/**
	 * Verifica se uma Data está dentro das LocalDate dadas
	 * @param begin
	 * @param end
	 * @return boolean
	 */
	public boolean isIntervalo(LocalDate begin, LocalDate end){
		return ((this.data.isAfter(begin) && this.data.isBefore(end)) || (this.data.equals(end) || this.data.equals(begin)));
	}

	/**
	 * Método equals da classe Data  
	 * @param obj
	 * @return boolean
	 */
	public boolean equals(Object obj){ 			 
		if(this==obj){
			return true; 
	} 			
		if(this==null || this.getClass() != obj.getClass()){ 
			return false;
	}
		final Data other = (Data) obj; 
			return (this.data.equals(other.getData()) && this.id == other.getId());		
	} 

	/**
	 * Devolve uma cópia de uma Data
	 * @return
	 */
	public Data clone(){ 
		return new Data(this);
	}

	/**
	 * Constrói e devolve uma string da class Data
	 * @return
	 */
	public String toString(){ 
		return "<" + id + ", " + data + ">";
	}
}
