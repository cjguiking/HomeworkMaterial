// Ceejay Guiking
// Assignment 6
// CS 302 - 1003
// 
// This program demonstrates the basic use of a binary search tree.

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Task
         {
           public:
            string element;
            int duration;
            int completionTime;
            bool critical; 
            Task() : element(""), duration(0), completionTime(0), 
                        critical(0) {};
            Task( string theString  , int theDuration , 
                  int theCompletion,
                   bool isCritical )
                 : element(theString), duration(theDuration),
                    completionTime(theCompletion),
                     critical(isCritical) {};

          };
 
        class TreeNode
        {
            Task info;
            TreeNode * leftChild;
            TreeNode * rightSibling;

            TreeNode() : info(), leftChild(NULL), rightSibling(NULL) {}; 

            TreeNode( Task theTask, TreeNode *lt, TreeNode *rt )
              : info( theTask ), leftChild( lt ), rightSibling( rt ) { }

			  
            friend class Tree;
            friend class TreeItr; 
        };

class TreeItr
        {
          public:
            TreeItr( ) : current( NULL ) { }
            bool isPast( ) const
              { return current == NULL; }
            bool hasChild( ) const
              { return current->leftChild != NULL; }

            void advanceSibling( )
              { if( !isPast( ) ) current = current->rightSibling; }
            void advanceChild( )
              { if( !isPast( ) ) current = current->leftChild; }

            Task getInfo(){  
				Task temp;
				if( !isPast( ) )
					return current->info;
				else
					return temp; 
			}
			
            void changeInfo( Task  x)
        	{
           	 current->info = x;
        	}
			
          private:
            TreeNode *current;    

            TreeItr( TreeNode *theNode )
              : current( theNode ) { }

            friend class Tree; 
        };

        class Tree
        {
          public:
            explicit Tree(){
				root = new TreeNode;
			}
			
			bool isEmpty( ) const{
				return root == NULL;
			}
			
            TreeItr createChild( TreeItr p ) {
				TreeNode* first = new TreeNode();
				TreeNode* second = new TreeNode();
				second = p.current;
				second->leftChild = first;

				TreeItr newItr(first);
				return newItr;
			}
			
			 TreeItr createSibling(TreeItr p)
			{
				TreeNode* first = new TreeNode();
				TreeNode* second = new TreeNode();
				second = p.current;
				second->rightSibling = first;

				TreeItr newItr(first);
				return newItr;
			}
			
            TreeItr TreeRoot( ) const{
				return TreeItr( root );
			}

          private:
            TreeNode *root;
        };
		
	void setupTree(Tree & T){
		TreeItr current, a,b,c,d,e,f,g,h,i,j,k,l,s,x,y,z;

		Task tmp;
		current = T.TreeRoot();

		tmp.element = "install product          ";
		tmp.duration = 15;
		tmp.completionTime = 0;
		tmp.critical = 1;
		current.changeInfo(tmp);

		s = T.createChild(current);

		tmp.element = "test user interface      ";
		tmp.duration = 11;
		tmp.completionTime = 0;
		tmp.critical = 1;
		s.changeInfo(tmp);

		l = T.createSibling(s);

		tmp.element = "set up platform          ";
		tmp.duration = 3;
		tmp.completionTime = 0;
		tmp.critical = 0;
		l.changeInfo(tmp);

		c = T.createChild(l);

		tmp.element = "order platform           ";
		tmp.duration = 2;
		tmp.completionTime = 0;
		tmp.critical = 0;
		c.changeInfo(tmp);

		k = T.createChild(s);

		tmp.element = "write I/O                ";
		tmp.duration = 7;
		tmp.completionTime = 0;
		tmp.critical = 1;
		k.changeInfo(tmp);

		j = T.createChild(k);

		tmp.element = "design I/O               ";
		tmp.duration = 3;
		tmp.completionTime = 0;
		tmp.critical = 0;
		j.changeInfo(tmp);

		i = T.createSibling(j);

		tmp.element = "design protocol          ";
		tmp.duration = 4;
		tmp.completionTime = 0;
		tmp.critical = 1;
		i.changeInfo(tmp);

		a = T.createSibling(l);

		tmp.element = "get CEO report           ";
		tmp.duration = 3;
		tmp.completionTime = 0;
		tmp.critical = 0;
		a.changeInfo(tmp);

		b = T.createSibling(a);

		tmp.element = "test main                ";
		tmp.duration = 11;
		tmp.completionTime = 0;
		tmp.critical = 1;
		b.changeInfo(tmp);

		d = T.createChild(a);

		tmp.element = "get CIO input            ";
		tmp.duration = 2;
		tmp.completionTime = 0;
		tmp.critical = 0;
		d.changeInfo(tmp);

		e = T.createChild(d);

		tmp.element = "get Dept report          ";
		tmp.duration = 1;
		tmp.completionTime = 0;
		tmp.critical = 0;
		e.changeInfo(tmp);

		f = T.createChild(b);

		tmp.element = "write main               ";
		tmp.duration = 7;
		tmp.completionTime = 0;
		tmp.critical = 1;
		f.changeInfo(tmp);

		g = T.createChild(f);

		tmp.element = "design driver            ";
		tmp.duration = 4;
		tmp.completionTime = 0;
		tmp.critical = 1;
		g.changeInfo(tmp);

		h = T.createSibling(g);

		tmp.element = "design utilities         ";
		tmp.duration = 2;
		tmp.completionTime = 0;
		tmp.critical = 0;
		h.changeInfo(tmp);

		z = T.createSibling(h);

		tmp.element = "design engine            ";
		tmp.duration = 4;
		tmp.completionTime = 0;
		tmp.critical = 1;
		z.changeInfo(tmp);

		y = T.createSibling(f);

		tmp.element = "install lib              ";
		tmp.duration = 1;
		tmp.completionTime = 0;
		tmp.critical = 0;
		y.changeInfo(tmp);

		x = T.createSibling(y);

		tmp.element = "install sort             ";
		tmp.duration = 1;
		tmp.completionTime = 0;
		tmp.critical = 0;
		x.changeInfo(tmp);


}
			
	// How to print out a Tree in Preorder
	void preorderPrint(TreeItr p)
	{
		cout << p.getInfo().element<< " " << p.getInfo().duration << endl;
		if ( p.hasChild() )
		{
			p.advanceChild();
			while ( !p.isPast() )
			{
				preorderPrint(p);
				p.advanceSibling();
			}
		}
	}
	
	void postorderPrint(TreeItr p)
	{
		if ( p.hasChild() )
		{
			p.advanceChild();
			while ( !p.isPast() )
			{
				postorderPrint(p);
				if(p.getInfo().critical == 1)
				{
					cout << p.getInfo().element << " " << "critical        " << p.getInfo().duration << endl;
				}
				else
					cout << p.getInfo().element << " " << "not critical    " << p.getInfo().duration << endl;
				p.advanceSibling();
			}
		}
	}
int main()
{
Tree theJobs;
TreeItr Top;
Top = theJobs.TreeRoot();
setupTree(theJobs);
cout << "PROJECT SCHEDULE" << endl;
postorderPrint(Top);
cout << Top.getInfo().element << " " << "critical        " << Top.getInfo().duration << endl;

return 0;
}