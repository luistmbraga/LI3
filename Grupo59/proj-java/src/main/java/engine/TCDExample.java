package engine;

import engine.Post;
import engine.Pergunta;
import engine.Resposta;
import engine.Users;
import engine.Tag;
import engine.Data;
import common.MyLog;
import common.Pair; 
import common.PairLong;
import li3.TADCommunity;

import org.w3c.dom.*;
import org.w3c.dom.Document;
import org.xml.sax.SAXException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;

import java.time.LocalDate;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Set;
import java.util.HashSet;
import java.util.stream.Collectors;
import java.util.Comparator;
import java.time.format.DateTimeFormatter;

import java.io.FileInputStream;
import java.io.FileNotFoundException;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Attribute;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;


/**
 *  Nesta classe encontram-se as estruturas principais usadas para responder às queries, faz-se o parsing de toda
 * a informação considerada necessária para estas mesmas estruturas e ainda contém o código de resposta às queries.
 *
 * @author Grupo 59
 */
public class TCDExample implements TADCommunity {

    /*TreeMap que contém todos os Users, cuja chave é o seu Id*/
    private	HashMap<Long,Users> users;
    /*TreeMap que contém todos os Posts, cuja chave é o seu Id*/
    private HashMap<Long,Post> posts;
    /*TreeMap que contém todas as Tags, cuja chave é o seu Id*/
    private HashMap<String,Long> tags;
    /*TreeMap que contém todas as respostas a determinada pergunta, cuja chave é o Id da pergunta*/
    private HashMap<Long,List<Data>> resPer;
    /*Lista com os todos Posts ordenados por data*/
    private List<Data> datas;

    /**
     * Construtor padrão de uma TCDExample
     */
    public TCDExample(){
        this.users = new HashMap<Long,Users>();
        this.posts = new HashMap<Long,Post>();
        this.tags = new HashMap<String,Long>();
        this.resPer = new HashMap<Long,List<Data>>();
        this.datas = new ArrayList<>();
    }

    /**
     * Carrega para a estrutura toda a informação relevante sobre os users
     * @param dumpPath
     */
    public void loadUsers(String dumpPath){
        File inputFile = new File(dumpPath + "Users.xml");

        try{

       		XMLInputFactory xmlInputFactory = XMLInputFactory.newInstance();

            XMLEventReader xmlEventReader = xmlInputFactory.createXMLEventReader(new FileInputStream(inputFile));

            while(xmlEventReader.hasNext()){
                XMLEvent user = xmlEventReader.nextEvent();

                if(user.isStartElement()){
                	StartElement euser = user.asStartElement();
                	if(euser.getName().getLocalPart().equals("row")){
                    
                   	    String id = (String) euser.getAttributeByName(new QName("Id")).getValue();
                    	Attribute shortBio = euser.getAttributeByName(new QName("AboutMe"));
                    	String shortBioS = new String("");
                    	if(shortBio != null) {shortBioS = (String) shortBio.getValue();}
                    	String dispname = (String) euser.getAttributeByName(new QName("DisplayName")).getValue();
                    	String reputation = (String) euser.getAttributeByName(new QName("Reputation")).getValue();
                    	long iduser = Long.parseLong(id);

                    	Users u = new Users(iduser, shortBioS, dispname, Long.parseLong(reputation));

                    	this.users.put(iduser, u);
                	} 
				}
			}	

        } catch(FileNotFoundException e){
        	e.printStackTrace();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * Carrega para a estrutura toda a informação relevante sobre os posts
     * @param dumpPath
     */
    public void loadPosts(String dumpPath){
        File inputFile = new File(dumpPath + "Posts.xml");

        try{

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

        XMLInputFactory xmlInputFactory = XMLInputFactory.newInstance();

            XMLEventReader xmlEventReader = xmlInputFactory.createXMLEventReader(new FileInputStream(inputFile));



            while(xmlEventReader.hasNext()){
                XMLEvent post = xmlEventReader.nextEvent();

                if(post.isStartElement()){
                	StartElement epost = post.asStartElement();
                	if(epost.getName().getLocalPart().equals("row")){

                   			String postType = (String) epost.getAttributeByName(new QName("PostTypeId")).getValue();
                    		String id = (String) epost.getAttributeByName(new QName("Id")).getValue();
                    		String userid = (String) epost.getAttributeByName(new QName("OwnerUserId")).getValue();
                    		String date = (String) epost.getAttributeByName(new QName("CreationDate")).getValue();

                    	if(postType.equals("1") || postType.equals("2")){
                        	LocalDate data = LocalDate.parse(date.substring(0, 10), formatter);
                        	long iduser = Long.parseLong(userid);
                        	Data postadi = new Data(Long.parseLong(id), data);
                        	long idpost = Long.parseLong(id);

                        	if(postType.equals("1")){
                            	String titulo = (String) epost.getAttributeByName(new QName("Title")).getValue();
                            	String tags = (String) epost.getAttributeByName(new QName("Tags")).getValue();
                            
                            	Pergunta per = new Pergunta(idpost, userid, data, titulo, tags);
                            	this.posts.put(idpost, per);
                        	}

                        	else{
                            	String parentid = (String) epost.getAttributeByName(new QName("ParentId")).getValue();
                            	String scr = (String) epost.getAttributeByName(new QName("Score")).getValue();
                            	String ncom = (String) epost.getAttributeByName(new QName("CommentCount")).getValue();
                            	long parentidl = Long.parseLong(parentid);

                            	Resposta respo = new Resposta(idpost, userid, data, parentidl, Long.parseLong(scr), Long.parseLong(ncom));
                            	this.posts.put(idpost, respo);

                            
                            	if(this.resPer.containsKey(parentidl)){
                                	this.resPer.get(parentidl).add(postadi);
                            	}
                            	else{
                                	List<Data> resp = new ArrayList<Data>();
                                	resp.add(postadi);
                                	this.resPer.put(parentidl, resp);
                            	}
 
                        	}
                        
                        List<Data> postUser = this.users.get(iduser).getPosts();
                        postUser.add(postadi);
                        this.datas.add(postadi);
                        this.users.get(iduser).setPosts(postUser);
                        
                    	}
             	    } 
            	}
            }
            this.datas = this.datas.stream().sorted((d1,d2)->d2.getData().compareTo(d1.getData())).collect(Collectors.toList());
            for(Users u : this.users.values()){
                List<Data> res = u.getPosts();
                res = res.stream().sorted((d1,d2)->d2.getData().compareTo(d1.getData())).collect(Collectors.toList());
                u.setPosts(res);
            }

        } catch(FileNotFoundException e){
        	e.printStackTrace();
        }catch (XMLStreamException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Carrega para a estrutura toda a informação relevante sobre as tags
     * @param dumpPath
     */
    public void loadTags(String dumpPath){
        File inputFile = new File(dumpPath + "Tags.xml");

        try{

            XMLInputFactory xmlInputFactory = XMLInputFactory.newInstance();

            XMLEventReader xmlEventReader = xmlInputFactory.createXMLEventReader(new FileInputStream(inputFile));



            while(xmlEventReader.hasNext()){
                XMLEvent tag = xmlEventReader.nextEvent();

                if(tag.isStartElement()){
                	StartElement etag = tag.asStartElement();
                	if(etag.getName().getLocalPart().equals("row")){

                    	Attribute idA = etag.getAttributeByName(new QName("Id"));
                    	Attribute tagnameA = etag.getAttributeByName(new QName("TagName"));
                    	long idtag = Long.parseLong(idA.getValue());                    	
                    	this.tags.put(tagnameA.getValue(),idtag);   
                    }                              
                }
            }

        } catch(FileNotFoundException e){
        	e.printStackTrace();
        }catch (XMLStreamException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    /**
     * Invoca todas as funções que carregam dados
     * @param dumpPath
     */
    public void load(String dumpPath) {
        this.loadUsers(dumpPath);
        this.loadPosts(dumpPath);
        this.loadTags(dumpPath);
    }

    /**
     * Query 1
     * @param id
     * @return Pair<String,String>
     */
    public Pair<String,String> infoFromPost(long id) {
        Pair<String,String> r = new Pair<String,String>("", "");
        boolean teste = true;
        while(this.posts.containsKey(id) && teste){
            Post p = this.posts.get(id);
            if(p.getClass().getSimpleName().equals("Pergunta")) { 
                r.setFst(((Pergunta) p).getTitulo()); 
                r.setSecond((this.users.get(Long.parseLong(p.getUserID()))).getDisplayName()); 
                teste = false;
            }
            else{
                id = ((Resposta) p).getParentID();
            }
        }
        return r;
    }

    /**
     * Query 2
     * @param N
     * @return List<Long>
     */
    public List<Long> topMostActive(int N) {
        return this.users.values().stream()
        						  .sorted((u1,u2)->Integer.compare(u2.getNPosts(), u1.getNPosts()))
        						  .limit(N)
        						  .map(Users::getID)
        						  .collect(Collectors.toList());
    }

    /**
     * Query 3
     * @param begin
     * @param end
     * @return Pair<Long,Long>
     */
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end) {
        long resp = 0;
        long perg = 0;
        List<Data> postInter = this.datas.stream()
        								 .filter(d->d.isIntervalo(begin, end))
        								 .collect(Collectors.toList());

        for(Data d : postInter){
            if(this.posts.get(d.getId()).getClass().getSimpleName().equals("Resposta")) resp++;
            else perg++;
        }

        return new Pair<Long,Long>(perg,resp);
    }

    /**
     * Query 4
     * @param tag
     * @param begin
     * @param end
     * @return List<Long>
     */
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end) {
              			return this.datas.stream()
        						   	     .filter(d->this.posts.get(d.getId()).isPergunta() && d.isIntervalo(begin,end))
        						   	     .filter(d->((Pergunta) this.posts.get(d.getId())).getTags().contains(tag))
        						   	     .map(Data::getId)
        						   		 .collect(Collectors.toList());
    
    }

    /**
     * Query 5
     * @param id
     * @return Pair<String, List<Long>>
     */
    public Pair<String, List<Long>> getUserInfo(long id) {
        String shortBio = "O user não existe";
        List<Long> ids = new ArrayList<Long>();

        if(this.users.containsKey(id)){
            shortBio = this.users.get(id).getShortBio();
            List<Data> aux = this.users.get(id).getPosts();
            ids = aux.stream()
            		 .map(Data::getId)
            		 .limit(10)
            		 .collect(Collectors.toList());
        }

        return new Pair<>(shortBio,ids);
    }

    /**
     * Query 6
     * @param N
     * @param begin 
     * @param end
     * @return List<Long>
     */
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) {
        List<Resposta> postInter = this.posts.values().stream()
                                                  .filter(d -> (!d.isPergunta() && d.isIntervalo(begin, end)))
                                                  .map(d->(Resposta)d)
                                                  .collect(Collectors.toList());

        List<Resposta> mostVoted = postInter.stream().sorted(Comparator.comparing(Resposta::getScr).reversed()).limit(N).collect(Collectors.toList());

        return mostVoted.stream().map(Resposta::getID).collect(Collectors.toList());
    }

    /**
     * Query 7
     * @param N
     * @param begin
     * @param end
     * @return List<Long>
     */
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end) {
        List<Post> postInter = this.posts.values().stream()
                                                  .filter(d -> d.isPergunta() && d.isIntervalo(begin, end))
                                                  .collect(Collectors.toList());
        List<PairLong> resultado = new ArrayList<PairLong>();
        for(Post p : postInter){
            long idp = p.getID();
          	long nresp = 0;
          	if(this.resPer.containsKey(idp)) nresp = this.resPer.get(idp).size();

          	resultado.add(new PairLong(idp, nresp));
        }

        return resultado.stream()
        				.sorted((r1,r2)->Long.compare(r2.getSnd(),r1.getSnd()))
        			    .limit(N)
        			    .map(PairLong::getFst)
        			    .collect(Collectors.toList());

    }

    /**
     * Query 8
     * @param N
     * @param word
     * @return List<Long>
     */
    public List<Long> containsWord(int N, String word) {
        List<Long> aux = new ArrayList<>();

        aux = this.datas.stream()
        				.filter(d -> this.posts.get(d.getId()).isPergunta() && ((Pergunta)this.posts.get(d.getId())).getTitulo().contains(word))
        				.limit(N)
        				.map(Data::getId)
        				.collect(Collectors.toList());

        return aux;
    }

    /**
     * Query 9
     * @param N
     * @param id1
     * @param id2
     * @return List<Long>
     */
    public List<Long> bothParticipated(int N, long id1, long id2) {
    	List<Long> resultado = new ArrayList<Long>();
    	if(this.users.containsKey(id1) && this.users.containsKey(id2)){
    		List<Data> postUser1 = this.users.get(id1).getPosts();			 // posts do user1
    		List<Data> postUser2 = this.users.get(id2).getPosts();			 // posts do user2
    		Set<Data> aux = new HashSet<Data>(); // Set de datas auxiliar que guardará os ids e datas deles para, posteriormente ordená-los
    		for(Data d1 : postUser1){ 			// percore os posts do user1
    			long idp1 = d1.getId();	
    			for(Data d2 : postUser2){				// percorre os posts do user2
    				long idp2 = d2.getId();
    				if(this.posts.get(idp1).getClass().getSimpleName().equals("Resposta")){
    					if(this.posts.get(idp2).getClass().getSimpleName().equals("Resposta")){
    						if(((Resposta) this.posts.get(idp2)).getParentID()==((Resposta) this.posts.get(idp1)).getParentID()){
    							long resid = ((Resposta)this.posts.get(idp1)).getParentID();
    							Data res = new Data(resid, this.posts.get(resid).getData());
    							aux.add(res);
    						}
    					}
    					else{
    						if(idp2 == ((Resposta)this.posts.get(idp1)).getParentID()) aux.add(d2.clone());
    					}
    				}
    				else{
    					if(this.posts.get(idp2).getClass().getSimpleName().equals("Resposta")){
    						if (((Resposta)this.posts.get(idp2)).getParentID()==idp1) aux.add(d1.clone());
    					}
    				}
    			}
    		}
    		aux = aux.stream().sorted((d1,d2)-> d2.getData().compareTo(d1.getData())).limit(N).collect(Collectors.toSet());
    		resultado = aux.stream().map(Data::getId).collect(Collectors.toList());
    	}
        return resultado;
    }

    /**
     * Query 10
     * @param id
     * @return long
     */
    public long betterAnswer(long id) {
        if (this.posts.containsKey(id) && this.resPer.containsKey(id)){
            List<Data> resp = this.resPer.get(id);
            double best = Double.MIN_VALUE;  
            long idbest = -2;
            for(Data d : resp){ 
                long idresp = d.getId();                   
                if(this.posts.containsKey(idresp)){ 
                    Resposta p = (Resposta) this.posts.get(idresp); 
                    long userid = Long.parseLong(p.getUserID());
                    if(this.users.containsKey(userid)){
                      double aux = p.calculoMedia(this.users.get(userid).getReputation()); 
                      if(aux>best){  
                           best = aux; 
                          idbest = idresp;
                        }
                   }
                }
            }            
            return idbest;
        }
        else return -1;
}
	
    /**
     * Query 11
     * @param N
     * @param begin
     * @param end
     * @return List<Long>
     */
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {
    		// Lista dos N users com mais reputação de sempre.
    		List<Users> bestUsers = this.users.values().stream()
    										 		   .sorted((u1,u2)-> Long.compare(u2.getReputation(), u1.getReputation()))
    										  		   .limit(N)
    										  		   .collect(Collectors.toList());
        	// Lista de datas que conterá o id e data de publicação de todos os posts (perguntas) naquele intervalo dos N users com mais reputação.
  			List<Data> postsInterBest = new ArrayList<>();
  			for (Users u : bestUsers){
  				List<Data> datasinter = u.getPosts().stream()
  													.filter(d -> (this.posts.get(d.getId()).isPergunta() && d.isIntervalo(begin,end)))
  													.collect(Collectors.toList());

  			    postsInterBest.addAll(datasinter);
  			}
  			List<Tag> aux= new ArrayList<>();
            for(Data d : postsInterBest){
            	String tags = ((Pergunta) this.posts.get(d.getId())).getTags();

            	for(int i = 1; i < tags.length();){
            		String auxtags = tags.substring(i);
            		int j = auxtags.indexOf(">");
            		String tag = auxtags.substring(0, j);
            		i += j+2;
            		boolean teste = false;
            		for(Tag t : aux){
            			if (teste) break;
            			if(t.getTagName().equals(tag)){
            				teste = true;
            				t.setTagId(t.getTagId()+1);
            			}
            		}
            		if(!teste){aux.add(new Tag(tag, 1));}
            	}
            }
          
        aux = aux.stream().sorted((t1, t2)-> Long.compare(t2.getTagId(), t1.getTagId())).limit(N).collect(Collectors.toList());

        return aux.stream().map(t->this.tags.get(t.getTagName())).collect(Collectors.toList());
       
    }

    /**
     * Liberta toda a memória alocada 
     */
    public void clear(){
            users.clear(); 
            posts.clear(); 
            tags.clear(); 
            resPer.clear(); 
            datas.clear();
    }
}
