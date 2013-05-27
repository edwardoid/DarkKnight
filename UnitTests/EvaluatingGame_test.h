#ifndef	UT_EVALUATING_GAME_H
#define UT_EVALUATING_GAME_H

#include <UnitTest++.h>
#include <PGNGameCollection.h>
#include <PGNGame.h>
#include <PGNMoveList.h>
#include <PGNMove.h>
#include <CETable.h>
#include <CEPiece.h>
#include <CEEngine.h>
#include <CEException.h>
#include <sstream>
#include <iostream>


#define GAME_STR "[Event \"Tbilisi\"] \
[Site \"Tbilisi\"] \
[Date \"1945.??.??\"] \
[Round \"?\"] \
[White \"Sereda , Viktor\"] \
[Black \"Petrosyan\"] \
[Result \"0-1\"] \
[WhiteElo \"\"] \
[BlackElo \"\"] \
[ECO \"E60\"] \
 \
1.d4 Nf6 2.Nf3 g6 3.g3 Bg7 4.Bg2 O-O 5.O-O d6 6.c4 Nbd7 7.Qc2 e5 8.dxe5 dxe5 9.Rd1 Re8 10.h3 c6 11.Be3 Qc7 12.Nc3 Nb6 13.Nd2 Be6 14.Na4 Nfd7 15.Nc5 Nxc5 \
16.Bxc5 f5 17.Nf3 Rad8 18.b3 h6 19.g4 e4 20.Nd4 Bc8 21.e3 Nd7 22.Bb4 Ne5 23.Bc3 Nd3 24.gxf5 gxf5 25.Ne2 Rd7 26.Ng3 Rf7 27.Nh5 Bxc3 28.Qxc3 Qe7 29.Nf4 Nxf4 \
30.exf4 Rg7 31.Qe3 Kh7 32.Kh2 Qh4 33.Rd2 Reg8 34.Bh1 c5 35.Rad1 b6 36.Rd6 Rg4 37.R6d2 Rxf4 38.Rg1 Rfg4 39.Rxg4 Rxg4 40.Rd6 Rg6 41.Rxg6 Kxg6 42.Bg2 Kf6 \
43.Qd2 Ke7 44.Qe3 Qg5 45.Qg3 f4 46.Qxg5+ hxg5 47.Bxe4 Kd6 48.Kg2 Ke5 49.Bg6 Kd4 50.Bh5 Bf5 51.Bd1 a5 52.a4 Be4+ 53.Kh2 Kd3 54.h4 gxh4 55.Kh3 f3 56.Kg4 h3 \
57.Kxh3 Kd2  0-1" 

static void printTableAndMove(CE::Engine& engine, pgn::MoveList moves, int moveNum)
{
	std::cout	<< ((moveNum % 2 == 0) ? "(whites)" : "(blacks)")
				<< "\nTable: \n"
				<< engine.getVirtualTable()
				<< "\n"
				<< "Move: "
				<< moves[moveNum / 2]
				<< std::endl;
}

TEST(evaluatingGame)
{
	std::stringstream ss;
	ss << GAME_STR;
	pgn::GameCollection games;
	ss >> games;
	CHECK_EQUAL(1, games.size());
	CE::Engine engine(*games.begin());

	int moveNum = 0;
	pgn::MoveList& moves = *engine.moves();
	try {
	while (engine.makeNextHalfMove())
	{
		if(moveNum == 76)
			int breakHere = 43;
//		printTableAndMove(engine, moves, moveNum++);
#ifdef _WIN32
//		system("pause");
#endif
	}
	}
	catch(CE::BadMove* e)
	{
		std::cerr << e->what() << std::endl;
	}
	catch(...)
	{
		std::cout	<< "Unhanded exception on move: "
					<< moveNum / 2 + 1
					<< ((moveNum % 2 == 0) ? "(whites)" : "(blacks)")
					<< std::endl;
		printTableAndMove(engine, moves, ++moveNum);
		CHECK_EQUAL(0, -1);
	}
}


#endif // UT_EVALUATING_GAME_H