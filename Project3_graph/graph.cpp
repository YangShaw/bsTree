template<class T>
class graph {
public:
	virtual int numOfVertice() const = 0;
	virtual int numOfEdge() const = 0;
	virtual bool existsEdge(int,int) const = 0;
	virtual void insertEdge(int,int,T) = 0;
	virtual void eraseEdge(int, int) = 0;
	
};
