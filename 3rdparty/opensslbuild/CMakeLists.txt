set(SRCDIR ${PROJECT_SOURCE_DIR}/3rdparty/openssl)
set(INCDIR ${SRCDIR}/include)
set(CRYPTO ${SRCDIR}/crypto)
set(SSL ${SRCDIR}/ssl)
set(ENGINES ${SRCDIR}/engines)

INCLUDE_DIRECTORIES(
	${INCDIR}
	${SRCDIR}
	${CRYPTO}
	${CRYPTO}/asn1
	${CRYPTO}/evp
)

ADD_DEFINITIONS(
	-DNO_WINDOWS_BRAINDEATH=1
	-DOPENSSL_NO_INLINE_ASM=1
	-DOPENSSL_NO_ASM=1
)

ADD_LIBRARY(OpenSSL STATIC
	# aes
	${CRYPTO}/aes/aes_cbc.c
	${CRYPTO}/aes/aes_cfb.c
	${CRYPTO}/aes/aes_core.c
	${CRYPTO}/aes/aes_ctr.c
	${CRYPTO}/aes/aes_ecb.c
	${CRYPTO}/aes/aes_ige.c
	${CRYPTO}/aes/aes_locl.h
	${CRYPTO}/aes/aes_misc.c
	${CRYPTO}/aes/aes_ofb.c
	${CRYPTO}/aes/aes_wrap.c

	# asn1
	${CRYPTO}/asn1/a_bitstr.c
	${CRYPTO}/asn1/a_bool.c
	${CRYPTO}/asn1/a_bytes.c
	${CRYPTO}/asn1/a_d2i_fp.c
	${CRYPTO}/asn1/a_digest.c
	${CRYPTO}/asn1/a_dup.c
	${CRYPTO}/asn1/a_enum.c
	${CRYPTO}/asn1/a_gentm.c
	${CRYPTO}/asn1/a_i2d_fp.c
	${CRYPTO}/asn1/a_int.c
	${CRYPTO}/asn1/a_mbstr.c
	${CRYPTO}/asn1/a_object.c
	${CRYPTO}/asn1/a_octet.c
	${CRYPTO}/asn1/a_print.c
	${CRYPTO}/asn1/a_set.c
	${CRYPTO}/asn1/a_sign.c
	${CRYPTO}/asn1/a_strex.c
	${CRYPTO}/asn1/a_strnid.c
	${CRYPTO}/asn1/a_time.c
	${CRYPTO}/asn1/a_type.c
	${CRYPTO}/asn1/a_utctm.c
	${CRYPTO}/asn1/a_utf8.c
	${CRYPTO}/asn1/a_verify.c
	${CRYPTO}/asn1/ameth_lib.c
	${CRYPTO}/asn1/asn1_err.c
	${CRYPTO}/asn1/asn1_gen.c
	${CRYPTO}/asn1/asn1_lib.c
	${CRYPTO}/asn1/asn1_par.c
	${CRYPTO}/asn1/asn_mime.c
	${CRYPTO}/asn1/asn_moid.c
	${CRYPTO}/asn1/asn_pack.c
	${CRYPTO}/asn1/bio_asn1.c
	${CRYPTO}/asn1/bio_ndef.c
	${CRYPTO}/asn1/d2i_pr.c
	${CRYPTO}/asn1/d2i_pu.c
	${CRYPTO}/asn1/evp_asn1.c
	${CRYPTO}/asn1/f_enum.c
	${CRYPTO}/asn1/f_int.c
	${CRYPTO}/asn1/f_string.c
	${CRYPTO}/asn1/i2d_pr.c
	${CRYPTO}/asn1/i2d_pu.c
	${CRYPTO}/asn1/n_pkey.c
	${CRYPTO}/asn1/nsseq.c
	${CRYPTO}/asn1/p5_pbe.c
	${CRYPTO}/asn1/p5_pbev2.c
	${CRYPTO}/asn1/p8_pkey.c
	${CRYPTO}/asn1/t_crl.c
	${CRYPTO}/asn1/t_pkey.c
	${CRYPTO}/asn1/t_req.c
	${CRYPTO}/asn1/t_spki.c
	${CRYPTO}/asn1/t_x509.c
	${CRYPTO}/asn1/t_x509a.c
	${CRYPTO}/asn1/tasn_dec.c
	${CRYPTO}/asn1/tasn_enc.c
	${CRYPTO}/asn1/tasn_fre.c
	${CRYPTO}/asn1/tasn_new.c
	${CRYPTO}/asn1/tasn_prn.c
	${CRYPTO}/asn1/tasn_typ.c
	${CRYPTO}/asn1/tasn_utl.c
	${CRYPTO}/asn1/x_algor.c
	${CRYPTO}/asn1/x_attrib.c
	${CRYPTO}/asn1/x_bignum.c
	${CRYPTO}/asn1/x_crl.c
	${CRYPTO}/asn1/x_exten.c
	${CRYPTO}/asn1/x_info.c
	${CRYPTO}/asn1/x_long.c
	${CRYPTO}/asn1/x_name.c
	${CRYPTO}/asn1/x_nx509.c
	${CRYPTO}/asn1/x_pkey.c
	${CRYPTO}/asn1/x_pubkey.c
	${CRYPTO}/asn1/x_req.c
	${CRYPTO}/asn1/x_sig.c
	${CRYPTO}/asn1/x_spki.c
	${CRYPTO}/asn1/x_val.c
	${CRYPTO}/asn1/x_x509.c
	${CRYPTO}/asn1/x_x509a.c
	${CRYPTO}/asn1/x_x509a.c

	# blowfish
	${CRYPTO}/bf/bf_cfb64.c
	${CRYPTO}/bf/bf_ecb.c
	${CRYPTO}/bf/bf_enc.c
	${CRYPTO}/bf/bf_ofb64.c
	${CRYPTO}/bf/bf_skey.c

	# bio
	${CRYPTO}/bio/b_dump.c
	${CRYPTO}/bio/b_print.c
	${CRYPTO}/bio/b_sock.c
	${CRYPTO}/bio/bf_buff.c
	${CRYPTO}/bio/bf_lbuf.c
	${CRYPTO}/bio/bf_nbio.c
	${CRYPTO}/bio/bf_null.c
	${CRYPTO}/bio/bio_cb.c
	${CRYPTO}/bio/bio_err.c
	${CRYPTO}/bio/bio_lib.c
	${CRYPTO}/bio/bss_acpt.c
	${CRYPTO}/bio/bss_bio.c
	${CRYPTO}/bio/bss_conn.c
	${CRYPTO}/bio/bss_dgram.c
	${CRYPTO}/bio/bss_fd.c
	${CRYPTO}/bio/bss_file.c
	${CRYPTO}/bio/bss_log.c
	${CRYPTO}/bio/bss_mem.c
	${CRYPTO}/bio/bss_null.c
	${CRYPTO}/bio/bss_sock.c

	# bignum
	${CRYPTO}/bn/bn_add.c
	${CRYPTO}/bn/bn_asm.c
	${CRYPTO}/bn/bn_blind.c
	${CRYPTO}/bn/bn_const.c
	${CRYPTO}/bn/bn_ctx.c
	${CRYPTO}/bn/bn_depr.c
	${CRYPTO}/bn/bn_div.c
	${CRYPTO}/bn/bn_err.c
	${CRYPTO}/bn/bn_exp.c
	${CRYPTO}/bn/bn_exp2.c
	${CRYPTO}/bn/bn_gcd.c
	${CRYPTO}/bn/bn_gf2m.c
	${CRYPTO}/bn/bn_kron.c
	${CRYPTO}/bn/bn_lib.c
	${CRYPTO}/bn/bn_mod.c
	${CRYPTO}/bn/bn_mont.c
	${CRYPTO}/bn/bn_mpi.c
	${CRYPTO}/bn/bn_mul.c
	${CRYPTO}/bn/bn_nist.c
	${CRYPTO}/bn/bn_prime.c
	${CRYPTO}/bn/bn_print.c
	${CRYPTO}/bn/bn_rand.c
	${CRYPTO}/bn/bn_recp.c
	${CRYPTO}/bn/bn_shift.c
	${CRYPTO}/bn/bn_sqr.c
	${CRYPTO}/bn/bn_sqrt.c
	${CRYPTO}/bn/bn_word.c

	# buffer
	${CRYPTO}/buffer/buf_err.c
	${CRYPTO}/buffer/buffer.c

	# camellia
	${CRYPTO}/camellia/camellia.c
	${CRYPTO}/camellia/cmll_cbc.c
	${CRYPTO}/camellia/cmll_cfb.c
	${CRYPTO}/camellia/cmll_ctr.c
	${CRYPTO}/camellia/cmll_ecb.c
	${CRYPTO}/camellia/cmll_misc.c
	${CRYPTO}/camellia/cmll_ofb.c

	# cast
	${CRYPTO}/cast/c_cfb64.c
	${CRYPTO}/cast/c_ecb.c
	${CRYPTO}/cast/c_enc.c
	${CRYPTO}/cast/c_ofb64.c
	${CRYPTO}/cast/c_skey.c

	# cms
	${CRYPTO}/cms/cms_asn1.c
	${CRYPTO}/cms/cms_att.c
	${CRYPTO}/cms/cms_cd.c
	${CRYPTO}/cms/cms_dd.c
	${CRYPTO}/cms/cms_enc.c
	${CRYPTO}/cms/cms_env.c
	${CRYPTO}/cms/cms_err.c
	${CRYPTO}/cms/cms_ess.c
	${CRYPTO}/cms/cms_io.c
	${CRYPTO}/cms/cms_lib.c
	${CRYPTO}/cms/cms_sd.c
	${CRYPTO}/cms/cms_smime.c

	# comp
	${CRYPTO}/comp/c_rle.c
	${CRYPTO}/comp/c_zlib.c
	${CRYPTO}/comp/comp_err.c
	${CRYPTO}/comp/comp_lib.c

	# conf
	${CRYPTO}/conf/conf_api.c
	${CRYPTO}/conf/conf_def.c
	${CRYPTO}/conf/conf_err.c
	${CRYPTO}/conf/conf_lib.c
	${CRYPTO}/conf/conf_mall.c
	${CRYPTO}/conf/conf_mod.c
	${CRYPTO}/conf/conf_sap.c

	# crypto
	${CRYPTO}/cpt_err.c
	${CRYPTO}/cryptlib.c
	${CRYPTO}/cversion.c
	${CRYPTO}/ebcdic.c
	${CRYPTO}/ex_data.c
	${CRYPTO}/mem.c
	${CRYPTO}/mem_clr.c
	${CRYPTO}/mem_dbg.c
	${CRYPTO}/o_dir.c
	${CRYPTO}/o_str.c
	${CRYPTO}/o_time.c
	${CRYPTO}/objects/o_names.c
	${CRYPTO}/uid.c

	# des
	${CRYPTO}/des/cbc3_enc.c
	${CRYPTO}/des/cbc_cksm.c
	${CRYPTO}/des/cbc_enc.c
	${CRYPTO}/des/cfb64ede.c
	${CRYPTO}/des/cfb64enc.c
	${CRYPTO}/des/cfb_enc.c
	${CRYPTO}/des/des_enc.c
	${CRYPTO}/des/des_old.c
	${CRYPTO}/des/des_old2.c
	${CRYPTO}/des/ecb3_enc.c
	${CRYPTO}/des/ecb_enc.c
	${CRYPTO}/des/ede_cbcm_enc.c
	${CRYPTO}/des/enc_read.c
	${CRYPTO}/des/enc_writ.c
	${CRYPTO}/des/fcrypt.c
	${CRYPTO}/des/fcrypt_b.c
	${CRYPTO}/des/ofb64ede.c
	${CRYPTO}/des/ofb64enc.c
	${CRYPTO}/des/ofb_enc.c
	${CRYPTO}/des/pcbc_enc.c
	${CRYPTO}/des/qud_cksm.c
	${CRYPTO}/des/rand_key.c
	${CRYPTO}/des/read2pwd.c
	${CRYPTO}/des/rpc_enc.c
	${CRYPTO}/des/set_key.c
	${CRYPTO}/des/str2key.c
	${CRYPTO}/des/xcbc_enc.c

	# dh
	${CRYPTO}/dh/dh_ameth.c
	${CRYPTO}/dh/dh_asn1.c
	${CRYPTO}/dh/dh_check.c
	${CRYPTO}/dh/dh_depr.c
	${CRYPTO}/dh/dh_err.c
	${CRYPTO}/dh/dh_gen.c
	${CRYPTO}/dh/dh_key.c
	${CRYPTO}/dh/dh_lib.c
	${CRYPTO}/dh/dh_pmeth.c
	${CRYPTO}/dh/dh_prn.c

	# dsa
	${CRYPTO}/dsa/dsa_ameth.c
	${CRYPTO}/dsa/dsa_asn1.c
	${CRYPTO}/dsa/dsa_depr.c
	${CRYPTO}/dsa/dsa_err.c
	${CRYPTO}/dsa/dsa_gen.c
	${CRYPTO}/dsa/dsa_key.c
	${CRYPTO}/dsa/dsa_lib.c
	${CRYPTO}/dsa/dsa_ossl.c
	${CRYPTO}/dsa/dsa_pmeth.c
	${CRYPTO}/dsa/dsa_prn.c
	${CRYPTO}/dsa/dsa_sign.c
	${CRYPTO}/dsa/dsa_vrf.c

	# dso
	${CRYPTO}/dso/dso_beos.c
	${CRYPTO}/dso/dso_dl.c
	${CRYPTO}/dso/dso_dlfcn.c
	${CRYPTO}/dso/dso_err.c
	${CRYPTO}/dso/dso_lib.c
	${CRYPTO}/dso/dso_null.c
	${CRYPTO}/dso/dso_openssl.c
	${CRYPTO}/dso/dso_vms.c
	${CRYPTO}/dso/dso_win32.c

	# ec
	${CRYPTO}/ec/ec2_mult.c
	${CRYPTO}/ec/ec2_smpl.c
	${CRYPTO}/ec/ec_ameth.c
	${CRYPTO}/ec/ec_asn1.c
	${CRYPTO}/ec/ec_check.c
	${CRYPTO}/ec/ec_curve.c
	${CRYPTO}/ec/ec_cvt.c
	${CRYPTO}/ec/ec_err.c
	${CRYPTO}/ec/ec_key.c
	${CRYPTO}/ec/ec_lib.c
	${CRYPTO}/ec/ec_mult.c
	${CRYPTO}/ec/ec_pmeth.c
	${CRYPTO}/ec/ec_print.c
	${CRYPTO}/ec/eck_prn.c
	${CRYPTO}/ec/ecp_mont.c
	${CRYPTO}/ec/ecp_nist.c
	${CRYPTO}/ec/ecp_smpl.c

	# ecdh
	${CRYPTO}/ecdh/ech_err.c
	${CRYPTO}/ecdh/ech_key.c
	${CRYPTO}/ecdh/ech_lib.c
	${CRYPTO}/ecdh/ech_ossl.c

	# ecdsa
	${CRYPTO}/ecdsa/ecs_asn1.c
	${CRYPTO}/ecdsa/ecs_err.c
	${CRYPTO}/ecdsa/ecs_lib.c
	${CRYPTO}/ecdsa/ecs_ossl.c
	${CRYPTO}/ecdsa/ecs_sign.c
	${CRYPTO}/ecdsa/ecs_vrf.c

	# engine
	${CRYPTO}/engine/eng_all.c
	${CRYPTO}/engine/eng_cnf.c
	${CRYPTO}/engine/eng_cryptodev.c
	${CRYPTO}/engine/eng_ctrl.c
	${CRYPTO}/engine/eng_dyn.c
	${CRYPTO}/engine/eng_err.c
	${CRYPTO}/engine/eng_fat.c
	${CRYPTO}/engine/eng_init.c
	${CRYPTO}/engine/eng_lib.c
	${CRYPTO}/engine/eng_list.c
	${CRYPTO}/engine/eng_openssl.c
	${CRYPTO}/engine/eng_pkey.c
	${CRYPTO}/engine/eng_table.c
	${CRYPTO}/engine/tb_asnmth.c
	${CRYPTO}/engine/tb_cipher.c
	${CRYPTO}/engine/tb_dh.c
	${CRYPTO}/engine/tb_digest.c
	${CRYPTO}/engine/tb_dsa.c
	${CRYPTO}/engine/tb_ecdh.c
	${CRYPTO}/engine/tb_ecdsa.c
	${CRYPTO}/engine/tb_pkmeth.c
	${CRYPTO}/engine/tb_rand.c
	${CRYPTO}/engine/tb_rsa.c
	${CRYPTO}/engine/tb_store.c

	# err
	${CRYPTO}/err/err.c
	${CRYPTO}/err/err_all.c
	${CRYPTO}/err/err_prn.c

	# evp
	${CRYPTO}/evp/bio_b64.c
	${CRYPTO}/evp/bio_enc.c
	${CRYPTO}/evp/bio_md.c
	${CRYPTO}/evp/bio_ok.c
	${CRYPTO}/evp/c_all.c
	${CRYPTO}/evp/c_allc.c
	${CRYPTO}/evp/c_alld.c
	${CRYPTO}/evp/digest.c
	${CRYPTO}/evp/e_aes.c
	${CRYPTO}/evp/e_bf.c
	${CRYPTO}/evp/e_camellia.c
	${CRYPTO}/evp/e_cast.c
	${CRYPTO}/evp/e_des.c
	${CRYPTO}/evp/e_des3.c
	${CRYPTO}/evp/e_idea.c
	${CRYPTO}/evp/e_null.c
	${CRYPTO}/evp/e_old.c
	${CRYPTO}/evp/e_rc2.c
	${CRYPTO}/evp/e_rc4.c
	${CRYPTO}/evp/e_rc5.c
	${CRYPTO}/evp/e_seed.c
	${CRYPTO}/evp/e_xcbc_d.c
	${CRYPTO}/evp/encode.c
	${CRYPTO}/evp/evp_acnf.c
	${CRYPTO}/evp/evp_enc.c
	${CRYPTO}/evp/evp_err.c
	${CRYPTO}/evp/evp_key.c
	${CRYPTO}/evp/evp_lib.c
	${CRYPTO}/evp/evp_pbe.c
	${CRYPTO}/evp/evp_pkey.c
	${CRYPTO}/evp/m_dss.c
	${CRYPTO}/evp/m_dss1.c
	${CRYPTO}/evp/m_ecdsa.c
	${CRYPTO}/evp/m_md2.c
	${CRYPTO}/evp/m_md4.c
	${CRYPTO}/evp/m_md5.c
	${CRYPTO}/evp/m_mdc2.c
	${CRYPTO}/evp/m_null.c
	${CRYPTO}/evp/m_ripemd.c
	${CRYPTO}/evp/m_sha.c
	${CRYPTO}/evp/m_sha1.c
	${CRYPTO}/evp/m_sigver.c
	${CRYPTO}/evp/m_wp.c
	${CRYPTO}/evp/names.c
	${CRYPTO}/evp/openbsd_hw.c
	${CRYPTO}/evp/p5_crpt.c
	${CRYPTO}/evp/p5_crpt2.c
	${CRYPTO}/evp/p_dec.c
	${CRYPTO}/evp/p_enc.c
	${CRYPTO}/evp/p_lib.c
	${CRYPTO}/evp/p_open.c
	${CRYPTO}/evp/p_seal.c
	${CRYPTO}/evp/p_sign.c
	${CRYPTO}/evp/p_verify.c
	${CRYPTO}/evp/pmeth_fn.c
	${CRYPTO}/evp/pmeth_gn.c
	${CRYPTO}/evp/pmeth_lib.c

	# hmac
	${CRYPTO}/hmac/hm_ameth.c
	${CRYPTO}/hmac/hm_pmeth.c
	${CRYPTO}/hmac/hmac.c

	# idea
	${CRYPTO}/idea/i_cbc.c
	${CRYPTO}/idea/i_cfb64.c
	${CRYPTO}/idea/i_ecb.c
	${CRYPTO}/idea/i_ofb64.c
	${CRYPTO}/idea/i_skey.c

	# krb5
	${CRYPTO}/krb5/krb5_asn.c

	# lhash
	${CRYPTO}/lhash/lh_stats.c
	${CRYPTO}/lhash/lhash.c

	# md4
	${CRYPTO}/md4/md4_dgst.c
	${CRYPTO}/md4/md4_one.c

	# md5
	${CRYPTO}/md5/md5_dgst.c
	${CRYPTO}/md5/md5_one.c

	# mdc2
	${CRYPTO}/mdc2/mdc2_one.c
	${CRYPTO}/mdc2/mdc2dgst.c

	# modes
	${CRYPTO}/modes/cbc128.c
	${CRYPTO}/modes/cfb128.c
	${CRYPTO}/modes/ctr128.c
	${CRYPTO}/modes/cts128.c
	${CRYPTO}/modes/ofb128.c

	# objects
	${CRYPTO}/objects/obj_dat.c
	${CRYPTO}/objects/obj_err.c
	${CRYPTO}/objects/obj_lib.c
	${CRYPTO}/objects/obj_xref.c

	# ocsp
	${CRYPTO}/ocsp/ocsp_asn.c
	${CRYPTO}/ocsp/ocsp_cl.c
	${CRYPTO}/ocsp/ocsp_err.c
	${CRYPTO}/ocsp/ocsp_ext.c
	${CRYPTO}/ocsp/ocsp_ht.c
	${CRYPTO}/ocsp/ocsp_lib.c
	${CRYPTO}/ocsp/ocsp_prn.c
	${CRYPTO}/ocsp/ocsp_srv.c
	${CRYPTO}/ocsp/ocsp_vfy.c

	# pem
	${CRYPTO}/pem/pem_all.c
	${CRYPTO}/pem/pem_err.c
	${CRYPTO}/pem/pem_info.c
	${CRYPTO}/pem/pem_lib.c
	${CRYPTO}/pem/pem_oth.c
	${CRYPTO}/pem/pem_pk8.c
	${CRYPTO}/pem/pem_pkey.c
	${CRYPTO}/pem/pem_seal.c
	${CRYPTO}/pem/pem_sign.c
	${CRYPTO}/pem/pem_x509.c
	${CRYPTO}/pem/pem_xaux.c
	${CRYPTO}/pem/pvkfmt.c

	# pkcs12
	${CRYPTO}/pkcs12/p12_add.c
	${CRYPTO}/pkcs12/p12_asn.c
	${CRYPTO}/pkcs12/p12_attr.c
	${CRYPTO}/pkcs12/p12_crpt.c
	${CRYPTO}/pkcs12/p12_crt.c
	${CRYPTO}/pkcs12/p12_decr.c
	${CRYPTO}/pkcs12/p12_init.c
	${CRYPTO}/pkcs12/p12_key.c
	${CRYPTO}/pkcs12/p12_kiss.c
	${CRYPTO}/pkcs12/p12_mutl.c
	${CRYPTO}/pkcs12/p12_npas.c
	${CRYPTO}/pkcs12/p12_p8d.c
	${CRYPTO}/pkcs12/p12_p8e.c
	${CRYPTO}/pkcs12/p12_utl.c
	${CRYPTO}/pkcs12/pk12err.c

	# pkcs7
	${CRYPTO}/pkcs7/bio_pk7.c
	${CRYPTO}/pkcs7/example.c
	${CRYPTO}/pkcs7/pk7_asn1.c
	${CRYPTO}/pkcs7/pk7_attr.c
	${CRYPTO}/pkcs7/pk7_dgst.c
	${CRYPTO}/pkcs7/pk7_doit.c
	${CRYPTO}/pkcs7/pk7_lib.c
	${CRYPTO}/pkcs7/pk7_mime.c
	${CRYPTO}/pkcs7/pk7_smime.c
	${CRYPTO}/pkcs7/pkcs7err.c

	# pqueue
	${CRYPTO}/pqueue/pqueue.c

	# rand
	${CRYPTO}/rand/md_rand.c
	${CRYPTO}/rand/rand_egd.c
	${CRYPTO}/rand/rand_err.c
	${CRYPTO}/rand/rand_lib.c
	${CRYPTO}/rand/rand_unix.c
	${CRYPTO}/rand/randfile.c

	# rc2
	${CRYPTO}/rc2/rc2_cbc.c
	${CRYPTO}/rc2/rc2_ecb.c
	${CRYPTO}/rc2/rc2_skey.c
	${CRYPTO}/rc2/rc2cfb64.c
	${CRYPTO}/rc2/rc2ofb64.c

	# rc4
	${CRYPTO}/rc4/rc4_enc.c
	${CRYPTO}/rc4/rc4_skey.c

	# ripemd
	${CRYPTO}/ripemd/rmd_dgst.c
	${CRYPTO}/ripemd/rmd_one.c

	# rsa
	${CRYPTO}/rsa/rsa_ameth.c
	${CRYPTO}/rsa/rsa_asn1.c
	${CRYPTO}/rsa/rsa_chk.c
	${CRYPTO}/rsa/rsa_depr.c
	${CRYPTO}/rsa/rsa_eay.c
	${CRYPTO}/rsa/rsa_err.c
	${CRYPTO}/rsa/rsa_gen.c
	${CRYPTO}/rsa/rsa_lib.c
	${CRYPTO}/rsa/rsa_none.c
	${CRYPTO}/rsa/rsa_null.c
	${CRYPTO}/rsa/rsa_oaep.c
	${CRYPTO}/rsa/rsa_pk1.c
	${CRYPTO}/rsa/rsa_pmeth.c
	${CRYPTO}/rsa/rsa_prn.c
	${CRYPTO}/rsa/rsa_pss.c
	${CRYPTO}/rsa/rsa_saos.c
	${CRYPTO}/rsa/rsa_sign.c
	${CRYPTO}/rsa/rsa_ssl.c
	${CRYPTO}/rsa/rsa_x931.c

	# seed
	${CRYPTO}/seed/seed.c
	${CRYPTO}/seed/seed_cbc.c
	${CRYPTO}/seed/seed_cfb.c
	${CRYPTO}/seed/seed_ecb.c
	${CRYPTO}/seed/seed_ofb.c

	# sha*
	${CRYPTO}/sha/sha1_one.c
	${CRYPTO}/sha/sha1dgst.c
	${CRYPTO}/sha/sha256.c
	${CRYPTO}/sha/sha512.c
	${CRYPTO}/sha/sha_dgst.c
	${CRYPTO}/sha/sha_one.c

	# stack
	${CRYPTO}/stack/stack.c

	# threads
	${CRYPTO}/threads/th-lock.c

	# ts
	${CRYPTO}/ts/ts_asn1.c
	${CRYPTO}/ts/ts_conf.c
	${CRYPTO}/ts/ts_err.c
	${CRYPTO}/ts/ts_lib.c
	${CRYPTO}/ts/ts_req_print.c
	${CRYPTO}/ts/ts_req_utils.c
	${CRYPTO}/ts/ts_rsp_print.c
	${CRYPTO}/ts/ts_rsp_sign.c
	${CRYPTO}/ts/ts_rsp_utils.c
	${CRYPTO}/ts/ts_rsp_verify.c
	${CRYPTO}/ts/ts_verify_ctx.c

	# txtdb
	${CRYPTO}/txt_db/txt_db.c

	# ui
	${CRYPTO}/ui/ui_compat.c
	${CRYPTO}/ui/ui_err.c
	${CRYPTO}/ui/ui_lib.c
	${CRYPTO}/ui/ui_openssl.c
	${CRYPTO}/ui/ui_util.c

	# whrlpool
	${CRYPTO}/whrlpool/wp_block.c
	${CRYPTO}/whrlpool/wp_dgst.c

	# x509
	${CRYPTO}/x509/by_dir.c
	${CRYPTO}/x509/by_file.c
	${CRYPTO}/x509/x509_att.c
	${CRYPTO}/x509/x509_cmp.c
	${CRYPTO}/x509/x509_d2.c
	${CRYPTO}/x509/x509_def.c
	${CRYPTO}/x509/x509_err.c
	${CRYPTO}/x509/x509_ext.c
	${CRYPTO}/x509/x509_lu.c
	${CRYPTO}/x509/x509_obj.c
	${CRYPTO}/x509/x509_r2x.c
	${CRYPTO}/x509/x509_req.c
	${CRYPTO}/x509/x509_set.c
	${CRYPTO}/x509/x509_trs.c
	${CRYPTO}/x509/x509_txt.c
	${CRYPTO}/x509/x509_v3.c
	${CRYPTO}/x509/x509_vfy.c
	${CRYPTO}/x509/x509_vpm.c
	${CRYPTO}/x509/x509cset.c
	${CRYPTO}/x509/x509name.c
	${CRYPTO}/x509/x509rset.c
	${CRYPTO}/x509/x509spki.c
	${CRYPTO}/x509/x509type.c
	${CRYPTO}/x509/x_all.c
	${CRYPTO}/x509v3/pcy_cache.c
	${CRYPTO}/x509v3/pcy_data.c
	${CRYPTO}/x509v3/pcy_lib.c
	${CRYPTO}/x509v3/pcy_map.c
	${CRYPTO}/x509v3/pcy_node.c
	${CRYPTO}/x509v3/pcy_tree.c
	${CRYPTO}/x509v3/v3_addr.c
	${CRYPTO}/x509v3/v3_akey.c
	${CRYPTO}/x509v3/v3_akeya.c
	${CRYPTO}/x509v3/v3_alt.c
	${CRYPTO}/x509v3/v3_asid.c
	${CRYPTO}/x509v3/v3_bcons.c
	${CRYPTO}/x509v3/v3_bitst.c
	${CRYPTO}/x509v3/v3_conf.c
	${CRYPTO}/x509v3/v3_cpols.c
	${CRYPTO}/x509v3/v3_crld.c
	${CRYPTO}/x509v3/v3_enum.c
	${CRYPTO}/x509v3/v3_extku.c
	${CRYPTO}/x509v3/v3_genn.c
	${CRYPTO}/x509v3/v3_ia5.c
	${CRYPTO}/x509v3/v3_info.c
	${CRYPTO}/x509v3/v3_int.c
	${CRYPTO}/x509v3/v3_lib.c
	${CRYPTO}/x509v3/v3_ncons.c
	${CRYPTO}/x509v3/v3_ocsp.c
	${CRYPTO}/x509v3/v3_pci.c
	${CRYPTO}/x509v3/v3_pcia.c
	${CRYPTO}/x509v3/v3_pcons.c
	${CRYPTO}/x509v3/v3_pku.c
	${CRYPTO}/x509v3/v3_pmaps.c
	${CRYPTO}/x509v3/v3_prn.c
	${CRYPTO}/x509v3/v3_purp.c
	${CRYPTO}/x509v3/v3_skey.c
	${CRYPTO}/x509v3/v3_sxnet.c
	${CRYPTO}/x509v3/v3_utl.c
	${CRYPTO}/x509v3/v3err.c

	# ssl
	${SSL}/bio_ssl.c
	${SSL}/d1_both.c
	${SSL}/d1_clnt.c
	${SSL}/d1_enc.c
	${SSL}/d1_lib.c
	${SSL}/d1_meth.c
	${SSL}/d1_pkt.c
	${SSL}/d1_srvr.c
	${SSL}/kssl.c
	${SSL}/s23_clnt.c
	${SSL}/s23_lib.c
	${SSL}/s23_meth.c
	${SSL}/s23_pkt.c
	${SSL}/s23_srvr.c
	${SSL}/s2_clnt.c
	${SSL}/s2_enc.c
	${SSL}/s2_lib.c
	${SSL}/s2_meth.c
	${SSL}/s2_pkt.c
	${SSL}/s2_srvr.c
	${SSL}/s3_both.c
	${SSL}/s3_clnt.c
	${SSL}/s3_enc.c
	${SSL}/s3_lib.c
	${SSL}/s3_meth.c
	${SSL}/s3_pkt.c
	${SSL}/s3_srvr.c
	${SSL}/ssl_algs.c
	${SSL}/ssl_asn1.c
	${SSL}/ssl_cert.c
	${SSL}/ssl_ciph.c
	${SSL}/ssl_err.c
	${SSL}/ssl_err2.c
	${SSL}/ssl_lib.c
	${SSL}/ssl_rsa.c
	${SSL}/ssl_sess.c
	${SSL}/ssl_stat.c
	${SSL}/ssl_txt.c
	${SSL}/t1_clnt.c
	${SSL}/t1_enc.c
	${SSL}/t1_lib.c
	${SSL}/t1_meth.c
	${SSL}/t1_reneg.c
	${SSL}/t1_srvr.c

	# engines
	${ENGINES}/e_4758cca.c
	${ENGINES}/e_aep.c
	${ENGINES}/e_atalla.c
	${ENGINES}/e_capi.c
	${ENGINES}/e_chil.c
	${ENGINES}/e_cswift.c
	${ENGINES}/e_gmp.c
	${ENGINES}/e_nuron.c
	${ENGINES}/e_padlock.c
	${ENGINES}/e_sureware.c
	${ENGINES}/e_ubsec.c
	${ENGINES}/ccgost/gost_ameth.c
	${ENGINES}/ccgost/gost_asn1.c
	${ENGINES}/ccgost/gost_crypt.c
	${ENGINES}/ccgost/gost_ctl.c
	${ENGINES}/ccgost/gost_eng.c
	${ENGINES}/ccgost/gost_keywrap.c
	${ENGINES}/ccgost/gost_md.c
	${ENGINES}/ccgost/gost_params.c
	${ENGINES}/ccgost/gost_pmeth.c
	${ENGINES}/ccgost/gost_sign.c
	${ENGINES}/ccgost/gost89.c
	${ENGINES}/ccgost/gost94_keyx.c
	${ENGINES}/ccgost/gost2001_keyx.c
	${ENGINES}/ccgost/gost2001.c
	${ENGINES}/ccgost/gosthash.c
	${ENGINES}/ccgost/e_gost_err.c
)

TARGET_LINK_LIBRARIES(OpenSSL)
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_GCC_VERSION ${MUMBLEKIT_GCC_VERSION})
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_GCC_C_LANGUAGE_STANDARD "c99")
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${PROJECT_SOURCE_DIR}/3rdparty/opensslbuild/OpenSSL.pch")
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_"GCC_THUMB_SUPPORT[arch=armv6]" "NO")
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_GCC_GENERATE_DEBUGGING_SYMBOLS "YES")
SET_TARGET_PROPERTIES(OpenSSL PROPERTIES XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")
