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

            // --- MAYBE MOVE BELOW TO ITS OWN "Advertisers" CONTRACT ----

            //@abi table ad i64
            struct ad {
                uint64_t ad_id;
                string redirect_link;
                string link_to_image;
                uint64_t num_to_display; // Number of times left for the ad to be displayed

                uint64_t primary_key() const { return ad_id; }

                EOSLIB_SERIALIZE(ad, (ad_id)(redirect_link)(link_to_image)(num_to_display))
            };

            // -----------------------------------------------------------

            //@abi table organization i64
            struct user {
                uint64_t account_name;
                string name;
                string username;
                uint64_t adclicks = 0;

                uint64_t primary_key() const { return account_name; }

                EOSLIB_SERIALIZE(user, (account_name)(name)(username)(adclicks))
            };   

            //@abi action
            void adduser(account_name account, string& name, string& username);

            //@abi action
            void getuser(const account_name account);

            //@abi action
            void updateclicks(account_name account); // update the number of ads user has clicked on

            // --- MAYBE MOVE BELOW TO ITS OWN "Advertisers" CONTRACT ----

            //@abi action
            void createad(account_name account, ad new_ad, uint64_t amount);   // When creating pass in a {...} for new_ad. 
                                                                                // Need to manually add id so find a way to automate.
                                                                                // Maybe fund in here too.

            //@abi action
            void fundad(account_name account, ad ad_to_fund, uint64_t amount);

            // //@abi action
            // void update_ad(account_name account, ad ad_to_update, string name, string link_to_ad);  ** implement last **

            // -----------------------------------------------------------

            typedef multi_index<N(user), user> userIndex;
            typedef multi_index<N(ad), ad> adIndex;
    };

    EOSIO_ABI(Users, (adduser)(getuser)(updateclicks)(createad)(fundad));
}