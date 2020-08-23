// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2020 The Vsync developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
	(     0, uint256("0x00000a47e5f67b18cc1bd58c9e50b5295370cc36df1245a2cd07bf6bb2486e72"))
	( 20000, uint256("0x00000000061abc7ca69c4c23fa8be87f0c04b087338061b25cdd53fcb3b0e7e5"))
	( 50000, uint256("0x0000000008f02a5d6a8e0231cc2313e7ce35ce70daf49483eda7e3f7e7633b43"))
	(100000, uint256("0x000000000d494283650e556dd6fc2dd1e140f4c6f81657da9c6818068ce2cabd"))
	(150000, uint256("0x0000000013d9e26b35cedbe7c389c19616c72dc33c7211af771a92f930c7c0de"))
	(200000, uint256("0x00000000025e7ab5beaf0c52f108e098660b1a069df2f7f693755e4262ea152e"))
	(275000, uint256("0x8033ed91c6b98b20f68600a85555785b87cc6a065ba1c62763c54dc9528b7064"))
	(297890, uint256("0x84f3a6e4f4f8e5ff5723cf0bf51ac9697d79440325948622eca61e7ca80de6ea"))
	(299282, uint256("0x2074e5ad8fb7391d074476a58eeb5d1612e218958175249cee5673810a3165d4"))
	(299498, uint256("0x5b40c02b8be526b7d57c511b20f0b97cd0c5b6a157b484e979fb0bba47d17fd0"))
	(429000, uint256("0x9ba77717d346aaa95dd30163057dec056dbd6bd217e07d901044a6887e59bab2"))
	(525000, uint256("0xe37423096dbc89ead0895c7aecd980fd2268ab33b40bc7c10b888f26ddbfe08f"))
	(590450, uint256("0x85c72b524c0310ca65c40151d4350e2b37f9d668683ef5b92e7e6c152de2c325"))
	(678019, uint256("0xc2062e25bb22a1cd90da615d93a4ce599994e158f5b97f0fc3ba81145028fa25"))
	(763560, uint256("0x31070dd70277fa1a55aced762db819f16cb09b8e0155f33ea4da5170ecf728cf"))
	(800000, uint256("0x8150252d830fa81285c540773a3c644cb3e559c7fa2d53b79b4575ac3485c857"))
	(842000, uint256("0x905dc93fb8c1243bee2476f1146750b90f2f4f98405771afecf0b50ea2ef0d33"))
	(844000, uint256("0x33ef90578ae809b874db2b845ae4c16579eb0b6feb7d52b5c918b4dd080830e1"))
	(850000, uint256("0xe694af25c02b1487739fa0b75814d52f5949eee9b79d8f53bc2519392209f484"))
	(850142, uint256("0x45db652de2b06fe05872cbf3343c37f08cff0ae801a2957f269032a14691085d"))
	(1047536, uint256("0xab7330cb36010daf2c85b835c62d51c19125ba6155cc527ec84ec54ea076e32d"))
	(1047971, uint256("0x13d8cb346c71ba27736662f9640b367a2c5b1dc8ee20fa45ad728764c2e7b50a"))
	(1400000, uint256("0x5b3f06c0ea5904f166d25a07fdeb33a50f14a87de73c1b52f49b5827b4057095"))
	(1404000, uint256("0xea5386147cfe7fddd2165475565108672366d130a8cb966aa7418207fd759d22"))
	(1404500, uint256("0x71c2e7fcd80e95b47da33235993447a1a6510f2ec3759bccdd1b3aea1a1cc777"))
	(1404532, uint256("0xe1384b3a16afa55704a51de7e62f329c77e6b4eb7915bb55428050de755357f5"))
    (1430000, uint256("0x0845cae63907158080efe983faaf850de9cd9193ce0664d6d96bed9b1d93f9bf"))
	(1438000, uint256("0xa7fa82cb7b304d2335f89196cf5867d1311d123a47bf61c188b89a7b323a4535"))
    (1438350, uint256("0x0758c1037c646714a222c0d70ba7d4ea38aa551e48ced0682d76138764ccd2f1"));

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1598195706, // * UNIX timestamp of last checkpoint block
    2667557,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2880        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1454124731,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x21;
        pchMessageStart[1] = 0x55;
        pchMessageStart[2] = 0x0a;
        pchMessageStart[3] = 0x5a;
        vAlertPubKey = ParseHex("0421fb0665876637d9d79d03a24f383393838fb9e3340858a6d5a70b079f4af57cfff3ca00310be5300d532adf6261ba98ac70d24d943a6be333bec6d7a6d93013");
        nDefaultPort = 65010;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Vsync starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Vsync: 1 minute
        nTargetSpacing = 1 * 60;  // Vsync: 1 minute
        nMaturity = 101;
        nMinStakeValue = 500;
        nMaxMoneyOut = 10000000000 * COIN;
        /** Height or Time Based Activations **/
        nLastPOWBlock = 259200;
        nModifierUpdateBlock = 1;

        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockEnforceInvalidUTXO = 350000;
        nZerocoinStartTime = 1524672000; //Wednesday, April 25, 2018 12:00:00 PM GMT-04:00
        nZerocoinStartHeight = 299282;

        const char* pszTimestamp = "Vsync 27-08-2017";

        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);

        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0421fb0665876637d9d79d03a24f383393838fb9e3340858a6d5a70b079f4af57cfff3ca00310be5300d532adf6261ba98ac70d24d943a6be333bec6d7a6d93013") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1503858596;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 525433;
        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x00000a47e5f67b18cc1bd58c9e50b5295370cc36df1245a2cd07bf6bb2486e72"));
        assert(genesis.hashMerkleRoot == uint256("0x55e07427d0ca8579ca7296908f464699df9a54782d28bda012656c9d33a3a3c4"));

        vSeeds.push_back(CDNSSeedData("vsyncseed.vsync.io", "vsyncseed.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node.vsync.io", "node.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node1.vsync.io", "node1.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node2.vsync.io", "node2.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node3.vsync.io", "node3.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node4.vsync.io", "node4.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node5.vsync.io", "node5.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node6.vsync.io", "node6.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node7.vsync.io", "node7.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node8.vsync.io", "node8.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node9.vsync.io", "node9.vsync.io"));
        vSeeds.push_back(CDNSSeedData("node10.vsync.io", "node10.vsync.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 70);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        //  BIP44 coin type is 'TBD'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x13)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        nPoolMaxTransactions = 3;
        strSporkKey = "047288f894b9743b998709571f7f516c36c1782c729b90cbd636d9b82c1ad7d9e164829e557b81a7431494f5c5511a2d1567f17aac68df3552d782deb8955bd3cd";
        
        strObfuscationPoolDummyAddress = "VTHprUHgceGPTTaAmajjcELftpUTKNhyJt";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 2;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("000010e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9");
        nDefaultPort = 51474;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Vsync: 1 day
        nTargetSpacing = 1 * 60;  // Vsync: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMinStakeValue = 500;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1454124731;
        genesis.nNonce = 2402015;
        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));
        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "vsync-testnet.seed.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "vsync-testnet.seed2.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("s3v3nh4cks.ddns.net", "s3v3nh4cks.ddns.net"));
        vSeeds.push_back(CDNSSeedData("88.198.192.110", "88.198.192.110"));
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet vsync addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet vsync script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet vsync BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet vsync BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet vsync BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Vsync: 1 day
        nTargetSpacing = 1 * 60;        // Vsync: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}
