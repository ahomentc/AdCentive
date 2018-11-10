#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <string>

namespace AdCentive
{
    using namespace eosio;
    using std::string;

    class Users : public contract {
        using contract::contract;

        public:

            Users(account_name self):contract(self) {}

            //@abi table organization i64
            struct user {
                uint64_t account_name;
                string name;
                string username;

                uint64_t primary_key() const { return account_name; }

                EOSLIB_SERIALIZE(user, (account_name)(name)(username))
            };   

            //@abi action
            void adduser(account_name account, string& name, string& username);

            //@abi action
            void getuser(const account_name account);

            typedef multi_index<N(user), user> userIndex;
    };

    EOSIO_ABI(Users, (adduser)(getuser));
}