package common;

import java.util.Objects;

/**
 * Classe destinada a designar um Pair polimórfico
 *
 * @author Grupo 59
 */
public class Pair<X,Y>{
    /*Primeiro elemento do par*/
    private X fst;
    /*Segundo elemento do par*/
    private Y snd;

    /**
     * Construtor parametrizado de um Pair
     */
    public Pair(X fst, Y snd) {
        this.fst = fst;
        this.snd = snd;
    }

    /**
     * Calcula a chave a partir dos elementos do Pair
     * @return int
     */
    public int hashCode() {
        int hashFst = fst != null ? fst.hashCode() : 0;
        int hashSnd = snd != null ? snd.hashCode() : 0;

        return (hashFst + hashSnd) * hashSnd + hashFst;
    }

    /**
     * Método equals de um Pair
     * @param o
     * @return boolean
     */
    public boolean equals(Object o) {
        if (o instanceof Pair) {
            Pair p = (Pair) o;
            return Objects.equals(this.fst, p.fst) && Objects.equals(snd, p.snd);
        }
        return false;
    }

    /**
     * Contrói e devolve uma String de um Pair
     * @return String
     */
    public String toString() {
        return "(" + fst + ", " + snd + ")";
    }

    /**
     * Devolve o primeiro elemento do Pair
     * @return X
     */
    public X getFst() {
        return fst;
    }

    /**
     * Define o primeiro elemento do Pair
     * @param X
     */
    public void setFst(X fst) {
        this.fst = fst;
    }

    /**
     * Devolve o segundo elemento do Pair
     * @return Y
     */
    public Y getSnd() {
        return snd;
    }

    /**
     * Define o segundo elemento do Pair
     * @param Y
     */
    public void setSecond(Y snd) {
        this.snd = snd;
    }
}