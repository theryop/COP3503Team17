#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Customer
{
    private:
   		 const string customername;
   	 int customerage;

    public:
    	Customer(string cn, int ca);
    	string getCustomerName();
    	int getCustomerAge();
   	 



};

int main()
{
 
   string sex;
   int age;  


   //Activity ranking variables
   int sports_rank;
   int videogames_rank;
   int reading_rank;
   int music_rank;
   int shopping_rank;
   int cooking_rank;
   int fashion_rank;
   int electronics_rank;
   int makeup_rank;
   int dancing_rank;
   
   //Activity product arrays
   
 //  vector<string> sports = {"Basketball", "Football", "Soccerball", "Volleyball", "Tennisball", "Tennis Racket", "Golf Balls", "Golf Clubs", "Baseball", "Hockey Puck", "Baseball Hat", "Hockey Sticks", "Pads", "Gloves");
 
 
   
   string sports [14] = {"Basketball", "Football", "Soccerball", "Volleyball", "Tennisball", "Tennis Racket", "Golf Balls", "Golf Clubs", "Baseball", "Hockey Puck", "Baseball Hat", "Hockey Sticks", "Pads", "Gloves"};
   vector<string> sportsvector (sports, sports + sizeof(sports)/sizeof(sports[0]));
   
   string videogames [12] = {"Xbox One", "Xbox One Controller", "Xbox One Games", "Playstation 4", "Playstation 4 Controller", "Playstation 4 Games", "Nintendo WiiU", "Nintendo WiiU Controller", "Nintendo WiiU Games", "Nintendo3DS", "Nintendo 3DS Games", "PC Games"};
   vector<string> videogamesvector (videogames, videogames + sizeof(videogames)/sizeof(videogames[0]));
    
    
   string reading[4] = {"Kindle Fire", "EBooks", "Barnes & Nobles Gift Card", "Redwall"};
   vector<string> readingvector (reading, reading + sizeof(reading)/sizeof(reading[0]));
   
   string music[10]= {"Itunes Gift Card", "Google Playstore Gift Card", "Beat by Dre Headphones", "Beats Pill Speakers", "Ipod Touch", "Auxillary Cable", "Amazon Music", "Spotify Membership", "Speakers", "Record Players"};
   vector<string> musicvector (music, music + sizeof(music)/sizeof(music[0]));
   
   string shopping[5] = {"Victoria’s Secret Gift Card", "Target Gift Card", "Nordstrom Gift Card", "Nike Gift Card", "Apple Gift Card"};
   vector<string> shoppingvector (shopping, shopping + sizeof(shopping)/sizeof(shopping[0]));

   string cooking[4] = {"Gordon Ramsay’s Home Cooking: Everything You Need to Know to Make Fabulous Food", "Pot", "Pan", "Kitchen Utensil Set"};
   vector<string> cookingvector (cooking, cooking + sizeof(cooking)/sizeof(cooking[0]));

   string fashion[4] = {"HIPSTER STUFF", "Shirts", "Underwear", "Pair of Socks"}; // please add stuff
   vector<string> fashionvector (fashion, fashion + sizeof(fashion)/sizeof(fashion[0]));

   string makeup[5] = {"NAKED3 eyeshadow palette", "Kat Von D Liner", "MAC lipstick", "Makeup brushes", "face masks"};
   vector<string> makeupvector (makeup, makeup + sizeof(makeup)/sizeof(makeup[0]));

   string electronics[13] = {"TVs", "Blu Ray Players", "Digital SLRs", "Laptops", "Mice and  Keyboard", "Desktop", "Printer", "USBs", "Webcams", "Tablets", "Phones", "GPS", "Softwares"};
   vector<string> electronicsvector (electronics, electronics + sizeof(electronics)/sizeof(electronics[0]));

   string dancing[9]= {"Steezy Membership", "Paul Ross", "World of Dance Tickets", "Academy of Villains", "Choreo Cookies", "GRV", "Brotherhood", "ACA", "Apocalypse Dance Crew"};
   vector<string> dancingvector (dancing, dancing + sizeof(dancing)/sizeof(dancing[0]));


srand ( time(NULL) );
 
   //Questionaire
   cout << "Question 1: Are you a Male or Female?" << endl;
   cin >> sex;

   cout << "Question 2: Please enter the age of the person you are buying a gift for?" << endl;
   cin >> age;
   
   //Activity Ranking Questions    
   cout << "Please rank the following interest on scale from 1 to 10 (1 being the lowest and 10 being the highest)" << endl;  
   cout << "(Lowest) 1--2--3--4--5--6--7--8--9--10 (Highest)" << endl;
   

   
   cout << "Sports?: " << endl;
   cin >> sports_rank;

   cout << "Video Games?: " << endl;    
   cin >> videogames_rank;
  	 
   
   cout << "Reading?: " << endl;
   cin >> reading_rank;

   cout << "Music?: " << endl;
   cin >> music_rank;
 
   cout << "Shopping?: " << endl;
   cin >> shopping_rank;

   cout << "Cooking?: " << endl;
   cin >> cooking_rank;
   

   cout << "Fashion?: " << endl;
   cin >> fashion_rank;
  	 
   cout << "Electronics?: " << endl;
   cin >> electronics_rank;
 
   cout << "Makeup?: " << endl;
   cin >> makeup_rank;

   cout << "Dancing?: " << endl;
   cin >> dancing_rank;
   
    for(int i=10; i>0; i--)
    {    
   	 if(sports_rank == i)
   	 {
   		 if(sports_rank >= 8 && sports_rank <=10)
   		 {

   				 int i = sports_rank;
   				 while(i>6)
   				 {
   				   
   					int RandIndex = rand() % sportsvector.size();
   					cout << sportsvector[RandIndex] << endl;
   					sportsvector.erase(sportsvector.begin()+RandIndex);
   					i--;   		 
   				 }
   				 
   		 }
   		 if(sports_rank >= 4 && sports_rank <=7)
   		 {
   					int RandIndex = rand() % sportsvector.size();
   					cout << sportsvector[RandIndex] << endl;
   					sportsvector.erase(sportsvector.begin()+RandIndex);
   			 
   	 	}
   		 
   	 }
   	 if(videogames_rank == i)
   	 {
   		 if(videogames_rank >= 8 && videogames_rank <=10)
   		 {
   				 int i = videogames_rank;
   				 while(i>6)
   				 {
   					int RandIndex1 = rand() % videogamesvector.size();
   					cout << videogamesvector[RandIndex1] << endl;
   					videogamesvector.erase(videogamesvector.begin()+RandIndex1);
   					i--;   		 
   				 }
   		 }   		 
   		 if(videogames_rank >=4 && videogames_rank <=7)
   		 {
   					 int RandIndex1 = rand() % videogamesvector.size();
   					cout << videogamesvector[RandIndex1] << endl;
   					videogamesvector.erase(videogamesvector.begin()+RandIndex1);
   			 
   		 }
   	 }
   	 if(reading_rank == i)
   	 {
   		    
   		 if(reading_rank >= 8 && reading_rank <=10)
   		 {
   			 int i = reading_rank;
   			 while(i>6)
   			 {
   			   
   				int RandIndex1 = rand() % readingvector.size();
   				cout << readingvector[RandIndex1] << endl;
   				readingvector.erase(readingvector.begin()+RandIndex1);
   				i--;   		 
   			 }
   		 }
   		 if(reading_rank >=4 && reading_rank<=7)
   		 {
   				 int RandIndex1 = rand() % readingvector.size();
   				cout << readingvector[RandIndex1] << endl;
   				readingvector.erase(readingvector.begin()+RandIndex1);
   	 	}
   		 
   		 
   	 }
   	 if(music_rank == i)
   	 {
   		  if(music_rank >= 8 && music_rank <=10)
   			 {
   				 int i = music_rank;   					 
   				 while(i>6)
   				 {
   				   
   					int RandIndex1 = rand() % musicvector.size();
   					cout << musicvector[RandIndex1] << endl;
   					musicvector.erase(musicvector.begin()+RandIndex1);
   					i--;   		 
   				 }
   			 }
   			 if(music_rank >=4 && music_rank<=7)
   			 {
   				  int RandIndex1 = rand() % musicvector.size();
   					cout << musicvector[RandIndex1] << endl;
   					musicvector.erase(musicvector.begin()+RandIndex1);
   		 	}
   	 }
   	 if(shopping_rank == i)
   	 {
   			 if(shopping_rank >= 8 && shopping_rank <=10)
   			 {
   				 int i = shopping_rank;
   				 while(i>6)
   				 {
   				   
   					int RandIndex1 = rand() % shoppingvector.size();
   					cout << shoppingvector[RandIndex1] << endl;
   					shoppingvector.erase(shoppingvector.begin()+RandIndex1);
   					i--;   		 
   				 }
   			 }
   			 if(shopping_rank >=4 && shopping_rank<=7)
   			 {
   				 int RandIndex1 = rand() % shoppingvector.size();
   					cout << shoppingvector[RandIndex1] << endl;
   					shoppingvector.erase(shoppingvector.begin()+RandIndex1);
   			 
   			 }
   	 
   	 
   		 
    	}
   	 if(cooking_rank == i)
   	 {
   			 if(cooking_rank >= 8 && cooking_rank <=10)
   			 {
   				 int i = cooking_rank;
   				 while(i>6)
   				 {
   				   
   					int RandIndex = rand() % cookingvector.size();
   					cout << cookingvector[RandIndex] << endl;
   					cookingvector.erase(cookingvector.begin()+RandIndex);
   					i--;   		 
   				 }
   			 }
   			 if(cooking_rank >= 4 && cooking_rank<=7)
   			 {
   				 
   					int RandIndex = rand() % cookingvector.size();
   					cout << cookingvector[RandIndex] << endl;
   					cookingvector.erase(cookingvector.begin()+RandIndex);
   				 
   		 	}

   		 
   	 }
   	 if(fashion_rank == i)
   	 {
   		 if(fashion_rank >= 8 && fashion_rank <=10)
   		 {
   			 int i = fashion_rank;
   			 while(i>6)
   			 {
   			   
   				int RandIndex = rand() % fashionvector.size();
   				cout << fashionvector[RandIndex] << endl;
   				fashionvector.erase(fashionvector.begin()+RandIndex);
   				i--;   		 
   			 }
   		 }
   		 if(fashion_rank >=4 && fashion_rank <=7)
   		 {
   			 int RandIndex = rand() % fashionvector.size();
   				cout << fashionvector[RandIndex] << endl;
   				fashionvector.erase(fashionvector.begin()+RandIndex);
   		 }
   				 
   	 }
   	 if(electronics_rank == i)
   	 {
   		  	 if(electronics_rank >= 8 && electronics_rank <=10)
   			 {
   				 int i = electronics_rank;
   				 while(i>6)
   				 {
   				   
   					int RandIndex1 = rand() % electronicsvector.size();
   					cout << electronicsvector[RandIndex1] << endl;
   					electronicsvector.erase(electronicsvector.begin()+RandIndex1);
   					i--;   		 
   				 }
   			 }
   			 if(electronics_rank >=4 && electronics_rank <=7)
   			 {
   				  int RandIndex1 = rand() % electronicsvector.size();
   					cout << electronicsvector[RandIndex1] << endl;
   					electronicsvector.erase(electronicsvector.begin()+RandIndex1);
   				 
   		 	}
   		 
   	 }
   	 if(makeup_rank == i)
   	 {
   		  	 if(makeup_rank >= 8 && makeup_rank <=10)
   			 {
   				 int i = makeup_rank;
   				 while(i>6)
   				 {
   				   
   					int RandIndex1 = rand() % makeupvector.size();
   					cout << makeupvector[RandIndex1] << endl;
   					makeupvector.erase(makeupvector.begin()+RandIndex1);
   					i--;   		 
   				 }
   			 }
   			 if(makeup_rank >=4 && makeup_rank<=7)
   			 {
   				  int RandIndex1 = rand() % makeupvector.size();
   					cout << makeupvector[RandIndex1] << endl;
   					makeupvector.erase(makeupvector.begin()+RandIndex1);
   				 
   			 }    
   	 
   	 }
   	 if(dancing_rank == i)
   	 {
   			 if(dancing_rank >= 8 && dancing_rank <=10)
   			 {
   				 int i = dancing_rank;
   				 while(i>6)
   				 {
   				   
   					int RandIndex1 = rand() % dancingvector.size();
   					cout << dancingvector[RandIndex1] << endl;
   					dancingvector.erase(dancingvector.begin()+RandIndex1);
   					i--;   		 
   				 }
   			 }
   			 if(dancing_rank >=4 && dancing_rank <=7)
   			 {
   				 int RandIndex1 = rand() % dancingvector.size();
   					cout << dancingvector[RandIndex1] << endl;
   					dancingvector.erase(dancingvector.begin()+RandIndex1);
   				 
   			 }
    
   		 
   	 }
   	 
   	 
    }    
}
