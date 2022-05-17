class requin
{
	private:
		unsigned short nbDents;
		unsigned short masse;
	public:
		unsigned short get_nbDents();
		unsigned short get_masse();
		void manger(unsigned short m,unsigned short S);
		void nager(unsigned short SS);
		requin(int value1,int value2);
		~requin();
};
