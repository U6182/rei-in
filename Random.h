#pragma once

/**

	@file Random.h
	@brief 乱数生成
	@author 木村憂哉
	@date 2020/10/23

*/

#include		<random>
#include		<cstdint>

class Rand {

private:

	//! 32ビット版メルセンヌ・ツイスタ
	std::mt19937		mt;

	//! 非決定論的な乱数
	std::random_device rd;

public:

	Rand() { mt.seed(rd()); }

	void		seed() { mt.seed(rd());}

	std::uint_fast32_t operator()() { return mt();}

	std::int_fast32_t operator()(const std::int_fast32_t max_) {

		std::uniform_int_distribution<> uid(0, ((max_ > 0) ? (std::int_fast32_t)max_ - 1 : 0));

		return uid(mt);

	}

	std::int_fast32_t operator()(const std::int_fast32_t min_, const std::int_fast32_t max_) {

		std::uniform_int_distribution<> uid((min_ <= max_) ? min_ : max_, (min_ <= max_) ? max_ : min_);
		return uid(mt);


	}

	bool	randBool(const double probability_) {

		std::bernoulli_distribution uid(probability_);
		return uid(mt);
	}

	bool	randBool() {

		std::uniform_int_distribution<> uid(0, 1);
		return ((uid(mt)) ? true : false);
	}

};

static thread_local Rand random;