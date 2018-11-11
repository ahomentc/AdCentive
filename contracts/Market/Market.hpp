#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

namespace AdCentive {
    using namespace eosio;
    using std::string;

    class Market : public contract {
        using contract::contract;

        public:

            Market(account_name self):contract(self) {}

            //@abi table ad i64
            struct market_ad {
                uint64_t ad_id;
                account_name user_belong_to;
                string name;
                string redirect_link;
                string link_to_image;
                uint64_t num_to_display;

                uint64_t primary_key() const { return ad_id; }

                EOSLIB_SERIALIZE(market_ad, (ad_id)(user_belong_to)(name)(redirect_link)(link_to_image)(num_to_display))
            };

            //@abi action
            void adclicked(account_name user, account_name website, uint64_t ad_id); // Action that occurs when ad is clicked 

            // void ad_clicked(account_name user, account_name website, ad clicked_ad); // Action that occurs when ad is clicked. ** another option **

            // //@abi action
            // void get_ad_by_id(uint64_t ad_id);            

            //@abi action
            void addad(account_name account, account_name user_belong_to, market_ad newAd); // Add an ad to the list of ads. Called by User

            //@abi action
            void removead(account_name account, uint64_t ad_id); // Remove an ad from the list of ads. Called by User

            //@abi action
            market_ad requestad(account_name account); // returns a random ad with num_to_display > 0. Updates ad's num_to_display -1.

            typedef multi_index<N(market_ad), market_ad> marketAdIndex;
    };

    EOSIO_ABI(Market, (adclicked)(addad)(removead)(requestad));
}
