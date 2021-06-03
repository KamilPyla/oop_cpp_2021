#include "Team.h"
#include <vector>

void Team::add(const Member & m) {
		_crew.insert(m);
	}

	std::ostream & Team::print(std::ostream & out) const {
		std::for_each(_crew.begin(), _crew.end(), [&](const Member & m) {
			out << m << "\n";
		});
			return out;
	}

	void Team::kill(std::function<bool(const Member &)> f){

		std::vector<Member> temp;

		std::for_each(_crew.begin(),_crew.end(), [&](const Member & m){
				temp.push_back(m);
				std::cout << m << "\n";
		});

		temp.erase(std::remove_if(temp.begin(),temp.end(),f),temp.end());

		_crew.clear();

		for (auto & el: temp)
			add(el);
		temp.clear();
	}

	Team Team::operator - (const Team  & t)const{
		Team team;

		std::set_intersection(_crew.begin(), _crew.end(),
													t._crew.begin(), t._crew.end(),
													std::inserter(team._crew, team._crew.begin()));
		
		return team;
	}
	Team Team::operator + (const Team & t)const{
		Team super_team;
		// for (auto el: _crew)
		// 	super_team.add(el);
		// for (auto el: t1._crew)
		// 	super_team.add(el);
		std::set_union(_crew.begin(), _crew.end(), 
										t._crew.begin(), t._crew.end(),
										std::inserter(super_team._crew, super_team._crew.begin()));
		
		return super_team;
	}


std::ostream & operator << (std::ostream & out, const Team & t) {
	return t.print(out);
}