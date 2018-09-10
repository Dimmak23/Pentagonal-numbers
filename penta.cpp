#include <iostream>

class Pentagonal
{

	private:
    int j=1, k=1, z=0, r=0;
    long long sum=0, dif=0;
    int MIN_j=0, MIN_k=0, MIN_z=0, MIN_r=0;
    bool FCT=true;

	public:
	// Constructor Pentagonal() step by step compare numbers
	// and looks if they pentagonal and fit all conditions
	Pentagonal()
	{
	    while(FCT)
	    {
	    	k=++j;
	    	while(--k>0)
	    	{
	    		sum=formula(j)+formula(k);
	    		dif=formula(j)-formula(k);
	    		// Obviously, index of pentagonal number equal 
	    		// sum of pair will be bigger than max index = "j".
	    		z=j;
	    		// Obviously, index of pentagonal number equal 
	    		// difference of numbers will be bigger than
	    		// min index = "k".
	    		r=k;
	    		if( (pentagon_chk(sum,z)) && (pentagon_chk(dif,r)) )
	    			{MIN_j=j; MIN_k=k; MIN_z=z; MIN_r=r; FCT=false;}
	    	}
	    }
	}

	// Method return "true" if given number is pentagonal,
	// return "false" if - not.
	bool pentagon_chk(long long X, int &z)
	{
		long long P=0; int i=z;
		while(P<X)
		{
			P=formula(i);
			z=i++;
			if(P==X) return true;
		}
		return false;
	}

	// Method formula calculate pentagonal number for given "i"
	long long formula(int i)
	{
		return (i*(3*i-1)/2);
	}

	// Destructor print result of calculations
	~Pentagonal()
	{
	    if(!(FCT))
	    	{
	    		std::cout<<"\nAfter research was founded pentagonal pair: \n";
	    		std::cout<<"P["<<MIN_j<<"]="<<formula(MIN_j)<<" and ";
	    		std::cout<<"P["<<MIN_k<<"]="<<formula(MIN_k)<<".\n";
	    		std::cout<<"\nThat have pentagonal sum: \n";
	    		std::cout<<"P["<<MIN_z<<"]="<<formula(MIN_z);
	    		std::cout<<"="<<formula(MIN_j);
	    		std::cout<<"+"<<formula(MIN_k)<<'\n';
	    		std::cout<<"\nand pentagonal difference: \n";
	    		std::cout<<"P["<<MIN_r<<"]="<<formula(MIN_r);
	    		std::cout<<"=|"<<formula(MIN_j);
	    		std::cout<<"-"<<formula(MIN_k)<<"|,\n";
	    		std::cout<<"which is minimum.\n";
	    	}
	    else std::cout<<"Not a single pair of pentagonal numbers in the scope!";
	}

};

int main()
{

	// Initialize calculations by creating object call of Pentagonal class,
	// constructor Pentagonal() will calculate numbers
	Pentagonal call;
    
    return 0;

    // Destructor calls when main() is terminated
}