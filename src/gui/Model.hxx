#ifndef Model_hxx
#define Model_hxx

#include <QObject>

class Model : public QObject
{
Q_OBJECT

public:

	virtual ~Model() {}
	virtual void loadMap( const std::string & filename ) = 0;
	virtual void registerPlayer( const std::string & playerName ) = 0;
	virtual std::string locationDetails() const = 0;
	virtual void move( const std::string & direction ) = 0;
	virtual std::string useItem( const std::string & itemName ) = 0;

	void start()
	{
		emit modify( locationDetails(), "" );
	}

public slots:
	
	void doMove( const std::string & direction )
	{
		std::string event = "";
		try
		{
			move( direction );
			event = "You move " + direction;
		}
		catch ( std::exception & e )
		{
			event = "You cannot move " + direction + "!";
		}
		emit modify( locationDetails(), event );
	}

	void doUseItem( const std::string & itemName )
	{
		std::string event = useItem( itemName );
		emit modify( locationDetails(), event );
	}

signals:

	void modify( const std::string & locationDetails, const std::string & event );

};

#endif
