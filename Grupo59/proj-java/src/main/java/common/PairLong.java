package common;

import java.util.Objects;


/**
 * Classe auxiliar usada na query 7
 * 
 * @author Grupo59
 */
public class PairLong{ 
    /*Primeiro long do par*/
	private long fst; 
    /*Segundo long do par*/
	private long snd; 

    /**
     * Construtor parametrizado de PairLong
     * @param fst
     * @param snd
     */
	public PairLong( long fst, long snd) {
        this.fst = fst;
        this.snd = snd;
    }

    /**
     * Construtor por cópia de um PairLong
     * @param pair
     */
    public PairLong(PairLong pair){ 
    	this.fst = pair.getFst(); 
    	this.snd = pair.getSnd();
    }

    /**
     * Devolve o primeiro elemento do par
     * @return
     */
    public long getFst(){ 
    	return this.fst; 
    }

    /**
     * Devolve o segundo elemento do par
     * @return 
     */
    public long getSnd(){ 
    	return this.snd;
    }

    /**
     * Define o primeiro elemento do par 
     * @param first
     */
    public void setFst(long first){ 
    	this.fst = first;
    }

    /**
     * Define o segundo elemento do par
     * @param second
     */
    public void setSnd(long second){ 
    	this.snd = second;
	}

    /**
     * Devolve uma cópia de um PairLong
     * @return
     */
    public PairLong clone(){ 
    	return new PairLong(this);
    }
    
    /**
     * Método equals de um PairLong
     * @param o
     * @return boolean
     */  	
	public boolean equals(Object o) {
    	if (this==o) return true; 
    	if (o.getClass() != this.getClass() || (o==null)) return false; 

    	PairLong p = (PairLong) o; 
    	return this.fst == p.getFst() && this.snd == p.getSnd();
    }

    /**
     * Constrói de devolve uma string de um PairLong
     * @return
     */
    public String toString() {
        return "(" + fst + ", " + snd + ")";
    }

}