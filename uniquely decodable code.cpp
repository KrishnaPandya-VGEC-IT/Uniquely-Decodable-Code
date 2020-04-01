/* Completely created by Krishna Pandya-170170116023 */

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cout<<"\n Enter the number of codes you want to enter : ";
	cin>>n;
	vector<string>v;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		string x;
		cout<<"\n Enter code : ";
		cin>>x;
		v.push_back(x);
	}
	for(i=0;i<v.size();i++)
	{
		cout<<"\n Element "<<i+1<<" : "<<v.at(i);
	}
	int original_size=v.size();
	for(i=v.size()-1;i>=0;i--)
	{
		for(j=0;j<v.size();j++)
		{
			if(i!=j)
			{
				int flag=0;
				int min;
				if(v.at(i).size()<=v.at(j).size())
				{
					flag=0;	//i size min
					min=v.at(i).size();
					//cout<<"\n Comparing "<<v.at(i)<<" and "<<v.at(j)<<" \t min : "<<min;
				}
				else
				{
					flag=1;	//j size min
					min=v.at(j).size();
					//cout<<"\n Comparing "<<v.at(i)<<" and "<<v.at(j)<<" \t min : "<<min;
				}
		
				if(flag==0)
				{
					if(v.at(j).substr(0,min).compare((v.at(i)))==0)		//if small string is prefix of big string
					{
						cout<<"\n\t matched "<<v.at(i)<<" and "<<v.at(j)<<" for "<<min<<" characters ";
						for(k=0;k<original_size;k++)
						{
							if(v.at(j).substr(min,v.at(j).size()).compare(v.at(k))==0)	//if str to be added is in the original elements
							{
								cout<<"\n\t Substr : "<<v.at(j).substr(min,v.at(j).size())<<" found at original array at position : "<<k+1<<" \t\t i.e.,vector v["<<k<<"] : "<<v.at(j).substr(min,v.at(j).size());
								cout<<"\n\n THE CODE IS NOT UNIQUELY DECODABLE!";		
								goto hi;
							}
						}
						int flag2=0;
						for(k=original_size;k<v.size();k++)
						{
							if(v.at(j).substr(min,v.at(j).size()).compare(v.at(k))==0)	//if 'string to be added' is found in added strings
							{
								flag2=1;
								break;
							}
						}
						if(flag2==0)	//if 'string to be added' is not found anywhere
						{
							cout<<"\n\t Adding string : "<<v.at(j).substr(min,v.at(j).size())<<" to end!";
							v.push_back(v.at(j).substr(min,v.at(j).size()));
							i=v.size()-1;
						}
					}
				}
				if(flag==1)
				{	
					if(v.at(i).substr(0,min).compare((v.at(j)))==0)		//if small string is prefix of big string
					{
						cout<<"\n\t matched "<<v.at(i)<<" and "<<v.at(j)<<" for "<<min<<" characters ";
						for(k=0;k<original_size;k++)
						{
							if(v.at(i).substr(min,v.at(i).size()).compare(v.at(k))==0)
							{
								cout<<"\n\t Substr : "<<v.at(i).substr(min,v.at(i).size())<<" found at original array at position : "<<k+1<<" \t\t i.e., vector v["<<k<<"] : "<<v.at(i).substr(min,v.at(i).size());
								cout<<"\n\n THE CODE IS NOT UNIQUELY DECODABLE!";		
								goto hi;
							}
						}
						int flag2=0;
						for(k=original_size;k<v.size();k++)
						{
							if(v.at(i).substr(min,v.at(i).size()).compare(v.at(k))==0)
							{
								flag2=1;
								break;
							}
						}
						if(flag2==0)
						{
							cout<<"\n\t Adding string : "<<v.at(i).substr(min,v.at(i).size())<<" to end!";
							v.push_back(v.at(i).substr(min,v.at(i).size()));
							i=v.size()-1;
						}
					}
				}
				cout<<"\n";
			}	
		}		
	}
	cout<<"\n\n THE CODE IS UNIQUELY DECODABLE!";
	hi:
		cout<<"\n\n----------VECTOR V AFTER ADDING ELEMENTS------------\n\n";
		for(i=0;i<v.size();i++)
		{
			cout<<"\n Element "<<i+1<<" : "<<v.at(i);
		}
return 0;
}
