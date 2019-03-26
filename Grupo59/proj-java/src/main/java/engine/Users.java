package engine; 

import engine.Data;

import java.util.Objects;
import java.util.List;
import java.util.ArrayList; 

/**
 * Classe destinada a designar os Users
 * 
 * @author Grupo 59
 */
public class Users { 
		/*Long com Id do User*/
		private long id;
		/*String com a shortbio do User*/
		private String shortbio;
		/*String com o nome do User*/    			
		private String  displayname;
		/*Long com a reputação do User*/			
		private long reputation;
		/*Lista de Datas com os posts do User*/		
		private List<Data> posts;

		/**
		 * Construtor padrão de um User
		 */
		public Users(){ 
			this.id = -10;
			this.shortbio = " "; 
			this.displayname = " "; 
			this.reputation = 0;  
			this.posts = new ArrayList<Data>();
		}

		/**
	 	 * Construtor parametrizado de um User
	 	 * @param id
		 * @param shrtbio
		 * @param displname
		 * @param rep
	 	 */
		public Users(long id, String shrtbio, String displname, long rep){ 
			this.id = id;
			this.shortbio = shrtbio; 
			this.displayname = displname; 
			this.reputation = rep; 
			this.posts = new ArrayList<Data>();
		}

		/**
		 * Construtor por cópia de um User
		 * @param u
		 */
		public Users(Users u){ 
			this.id = u.getID();
			this.shortbio = u.getShortBio(); 
			this.displayname = u.getDisplayName(); 
			this.reputation = u.getReputation(); 
			this.posts = u.getPosts(); 
		}

		/**
		 * Devolve o Id do User
		 * @return
		 */
		public long getID(){
			return this.id;
		}

		/**
		 * Define o Id do User
		 * @param id
		 */
		public void setID(long id){
			this.id = id;
		}
		
		/**
		 * Devolve a short bio do User
		 * @return 
		 */
		public String getShortBio(){ 
			return this.shortbio;
		}

		/**
		 * Define a short bio do User
		 * @param shrtbio
		 */
		public void setShortBio(String shrtbio){ 
			this.shortbio = shrtbio;
		}

		/**
		 * Devolve o display name do User
		 * @return
		 */
		public String getDisplayName(){ 
			return this.displayname;
		}

		/**
		 * Define o display name do User
		 * @param displname
		 */
		public void setDisplayName(String displname){ 
			this.displayname = displname;
		}

		/**
		 * Devolve a reputação do User
		 * @return
		 */
		public long getReputation(){ 
			return this.reputation;
		}

		/**
		 * Define a reputação do User
		 * @param rep
		 */
		public void setReputation(long rep){ 
			this.reputation = rep;
		}

		/**
		 * Devolve uma cópia da lista de Datas com os posts do User
		 * @return
		 */
		public List<Data> getPosts(){
			 List<Data> res = new ArrayList<Data>();
			 List<Data> aux = this.posts;
			 for(Data data : aux){
			 	res.add(data.clone());
			 }
			 return res;
		}

		/**
		 * Define a lista de Datas com os posts do User
		 * @param datas
		 */
		public void setPosts(List<Data> datas){
			this.posts = datas;
		}

		/**
		 * Devolve o número de posts que o User publicou
		 * @return
		 */
		public int getNPosts(){
			return this.posts.size();
		}

		/**
		 * Método equals de um User
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
			final Users other = (Users) obj; 

			
			int size = this.posts.size();
			List<Data> aux = other.getPosts();

			if(this.posts.size() != aux.size()) return false;

			for(int i = 0; i < size; i++){
				if(this.posts.get(i) != aux.get(i)) return false;
			}

			return (this.id == other.getID() && this.shortbio.equals(other.getShortBio()) && this.displayname.equals(other.getDisplayName()) 
				&& this.reputation == other.getReputation());
		} 

		/**
		 * Devolve uma cópia de um User
		 * @return 
		 */
		public Users clone(){ 
			return new Users(this);
		}
 
 		/**
 	 	 * Constrói e devolve uma string da class Tag
	 	 * @return
	 	 */
		public String toString(){ 
			return "<" + id + ", " + shortbio + ", " + displayname + ", " + reputation + ", " + posts.toString() + ">"; 
		} 
}
