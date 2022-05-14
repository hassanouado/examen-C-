#include <iostream>
#include <conio.h>
using namespace std;
//la class Suite
class Suite{
	int NB;
	float *S;
	public:
		Suite(){
			NB=0;
		}
		Suite(int ,float ,float);
		Suite(Suite&);
		float *getadd(){
			return S;
		}
		int getN(){
			return NB;
		}
		~Suite();
		void affiche();
		int Meme(Suite);
		Suite oppose();
		Suite Homo_Suite(float);
		Suite Produit_Suite(Suite);
		float Prod_Suite_Scal(Suite);
		Suite somme_Suite(Suite);
		Suite operator+(Suite);
		float operator*(Suite);
		Suite operator*(float );
}; 
//le constructeur de la class 
Suite::Suite(int n,float a,float b){
	this->NB=n;
	this->S=new float(NB);
	this->S[0]=a;
	this->S[1]=b;
	for(int i=2;i<NB;i++){
		this->S[i]=(3*this->S[i-2])+5*(this->S[i-1])+1;
	}
}
//le constructeur par recopie
Suite::Suite(Suite& s1){
	this->NB=s1.NB;
	this->S=new float(NB);
	for(int i=0;i<NB;i++){
		this->S[i]=s1.S[i];
	} 
}
//le destructeur dela class Suite
Suite::~Suite(){
	delete S;
}
void Suite::affiche(){
	for(int i=0;i<NB;i++){
		cout<<this->S[i]<<"  ";
	}
	cout<<endl;
}
//verifier si les deux suite sont meme
int Suite::Meme(Suite s1){
	return (s1.NB==this->NB)&&(s1.S[0]==this->S[0])&&(s1.S[1]==this->S[1]);
}
//methode retourner l'opposee d'une suite 
Suite Suite::oppose(){
	//Suite res(this->NB,-this->S[0],-this->S[1]);
	Suite res;
	res.NB=this->NB;
	res.S=new float(NB);
	for(int i=0;i<NB;i++){
		res.S[i]=-this->S[i];
	}
	return res;
	
}
//methode permettant de multiplier tous les element par un reel
Suite Suite::Homo_Suite(float f1){
	Suite resp;
	resp.NB=this->NB;
	resp.S=new float(NB);
	for(int i=0;i<NB;i++){
		resp.S[i]=this->S[i]*f1;
	}
	return resp;
}
//methode permettant de multiplier tous les element de deux suite
Suite Suite::Produit_Suite(Suite v){
	Suite prodSuite;
	prodSuite.NB=this->NB;
	prodSuite.S=new float(NB);
	for(int i=0;i<NB;i++){
		prodSuite.S[i]=(this->S[i])*(v.S[i]);
	}
	return prodSuite;
}
//claculer la somme des termes d'une retourner par methode Produit_Suite()
float Suite::Prod_Suite_Scal(Suite c){
        Suite res;
        float sum=0;
     	res.NB=this->NB;
	    res.S=new float(NB);
	    for(int i=0;i<NB;i++){
		res.S[i]=this->S[i]*c.S[i];
	}
	    for(int i=0;i<NB;i++){
		sum+=res.S[i];
	}
	return sum;
	
}
//methode de calculer la somme de deux suite
Suite Suite::somme_Suite(Suite v){
	Suite prodSuite;
	prodSuite.NB=this->NB;
	prodSuite.S=new float(NB);
	for(int i=0;i<NB;i++){
		prodSuite.S[i]=(this->S[i])+(v.S[i]);
	}
	return prodSuite;
}
//operateur a la meme role que la methode somme_Suite() 
Suite Suite::operator+(Suite v){
	Suite prodSuite;
	prodSuite.NB=this->NB;
	prodSuite.S=new float(NB);
	for(int i=0;i<NB;i++){
		prodSuite.S[i]=(this->S[i])+(v.S[i]);
	}
	return prodSuite;
}
//operateur a la meme role que la methode Produit_Suite()
float Suite::operator*(Suite v){
	 Suite res;
        float sum=0;
     	res.NB=this->NB;
	    res.S=new float(NB);
	    for(int i=0;i<NB;i++){
		res.S[i]=this->S[i]*v.S[i];
	}
	    for(int i=0;i<NB;i++){
		sum+=res.S[i];
	}
	return sum;
}
//operateur a la meme role que la methode Homo_Suite()
Suite Suite::operator*(float f1){
	Suite prodSuite;
	prodSuite.NB=this->NB;
	prodSuite.S=new float(NB);
	for(int i=0;i<NB;i++){
		prodSuite.S[i]=(this->S[i])*f1;
	}
	return prodSuite;
}
//class suiteboen
class SuiteBorne:public Suite{
	float Min,Max;
	public:
		SuiteBorne(int ,float ,float);
		float GetMax();
		float GetMin();
		void Setlimites(float,float);
		void affiche();
};
//constructeur de la class SuiteBorne
SuiteBorne::SuiteBorne(int n,float a,float b):Suite(n,a,b){
   this->Max=this->GetMax();
   this->Min=this->GetMin();	
}
//methode de retourner le maximaux des terme d'une suite
float SuiteBorne::GetMax(){
	float max=this->getadd()[0];
	for(int i=0;i<this->getN();i++){
		if(this->getadd()[i]>max)
		max=this->getadd()[i];
	}
	return max;
}
//methode de retourner le minimaux des terme d'une suite
float SuiteBorne::GetMin(){
	float min=this->getadd()[0];
	for(int i=0;i<this->getN();i++){
		if(this->getadd()[i]<min)
		min=this->getadd()[i];
	}
	return min;
}
//methode permet de modifier le max et le min
void SuiteBorne::Setlimites(float max,float min){
	this->Max=max;
	this->Min=min;
}
//affichage 
void SuiteBorne::affiche(){
	Suite::affiche();
	cout<<" la borne superieur est :"<<this->Max<<" et la borne inferieur est :"<<this->Min<<endl;
}
main(){
	Suite s1(5,1,2);
	Suite s2;
	SuiteBorne sb1(6,2,4);
	cout<<"//********************affiche de la classs derivee****************************************//"<<endl;
	sb1.affiche();
	float f1,f2=4;
	Suite s3(5,3,4);
    cout<<"//*****************************afficher les deux suite s1 et s2**************************//"<<endl;
	s1.affiche();
	s3.affiche();
	cout<<"//****************************afficher si s1 s'est la meme que s3 et 0 s'est non**********//"<<endl;
	cout<<"la suite s1 s\' est la meme que la suite s3 :"<<s1.Meme(s3)<<endl;
	s2=s1.oppose();
	cout<<"//*************************afficher la suite oppose de la suite s1*********************//"<<endl;
	s2.affiche();
	s2=s1.Homo_Suite(3);
	cout<<"//*************************afficher la suite retourner la fonction Homo_Suite() *********************//"<<endl;
	s2.affiche();
	s2=s1.Produit_Suite(s3);
	cout<<"//*************************afficher la suite retourner la fonction Produit_Suite()*********************// "<<endl;
	s2.affiche();
	cout<<"//*************************la somme des terme est:"<<s1.Prod_Suite_Scal(s3)<<endl;
	s2=s1.somme_Suite(s3);
	cout<<"//*************************afficher la suite represente la somme de deux suite *********************//"<<endl;
	s2.affiche();
	s2=s1+s3;
	cout<<"//*************************afficher la suite represente la somme de deux suite avec operateur *********************//"<<endl;
	s2.affiche();
	cout<<"//*************************afficher la some des trme represente la multiplication  de deux suite avec operateur *********************//"<<endl;
	f1=s1*s3;
	cout<<"\n \t "<<f1<<endl;
	s2=s1*3;
	cout<<"//****************afficher la suite represente la multiplication de la suite et un nombre reel ************//"<<endl;
	s2.affiche();
	getch();
	
	
}
