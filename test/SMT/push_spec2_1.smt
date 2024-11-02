(set-logic ALL)
(set-option :produce-models true)
(set-option :produce-unsat-cores true)

; Memory cells
(define-fun memory_cell ((l Int)) Bool
    (and (<= 0 l) (<= l 7))
)

; Position and implementation variables
(declare-const p0_in0 Int)
(assert (memory_cell p0_in0))
(declare-const pm_in0 Int)
(assert (memory_cell pm_in0))
(declare-const pn_in0 Int)
(assert (memory_cell pn_in0))

(declare-const p_new_out0 Int)
(assert (memory_cell p_new_out0))
(declare-const p0_out0 Int)
(assert (memory_cell p0_out0))
(declare-const pm_out0 Int)
(assert (memory_cell pm_out0))
(declare-const pn_out0 Int)
(assert (memory_cell pn_out0))

(assert (! (not (= p_new_out0 p0_out0)) :named p_unique_p_new_p0_out0))
(assert (! (not (= p_new_out0 pn_out0)) :named p_unique_p_new_pn_out0))


; definition of anchor/member variables
(declare-const back_in0 Int)
(assert (memory_cell back_in0))
(declare-const back_out0 Int)
(assert (memory_cell back_out0))
(declare-const end_in0 Int)
(assert (memory_cell end_in0))
(declare-const end_out0 Int)
(assert (memory_cell end_out0))
(declare-const begin_in0 Int)
(assert (memory_cell begin_in0))
(declare-const begin_out0 Int)
(assert (memory_cell begin_out0))
(declare-const head_in0 Int)
(assert (memory_cell head_in0))
(declare-const head_out0 Int)
(assert (memory_cell head_out0))


; nextto relations
(define-fun nextto_in0 ((l Int) (r Int)) Bool
  false)
(define-fun nextto_out0 ((l Int) (r Int)) Bool
  (and (= l pn_out0)  (= r pm_out0) (< l r))
  )
(assert (!(nextto_out0 pn_out0 pm_out0) :named nextto_out0_pn_pm))


; reachable relations
(define-fun-rec reachable_in0 ((l Int) (r Int)) Bool
  (or (and (= l p0_in0)  (= r pn_in0) (<= l r))
      (= l r)
      (nextto_in0 l r)
      (exists ((m Int)) (and (nextto_in0 l m) (reachable_in0 m r)))
      (exists ((m Int)) (and (reachable_in0 l m) (nextto_in0 m r)))))
(assert (!(reachable_in0 p0_in0 pn_in0) :named reach_in0_p0_pn))
(define-fun-rec reachable_out0 ((l Int) (r Int)) Bool
  (or (and (= l p0_out0)  (= r pn_out0) (<= l r))
      (= l r)
      (nextto_out0 l r)
      (exists ((m Int)) (and (nextto_out0 l m) (reachable_out0 m r)))
      (exists ((m Int)) (and (reachable_out0 l m) (nextto_out0 m r)))))
(assert (!(reachable_out0 p0_out0 pn_out0) :named reach_out0_p0_pn))


; aliases
(assert (! (= end_in0 0) :named alias_end_in0_0))
(assert (! (= head_in0 0) :named alias_head_in0_0))
(assert (! (= back_in0 pn_in0) :named alias_back_in0_pn_in0))
(assert (! (= begin_in0 p0_in0) :named alias_begin_in0_p0_in0))
(assert (! (= end_out0 p_new_out0) :named alias_end_out0_p_new_out0))
(assert (! (= head_out0 p_new_out0) :named alias_head_out0_p_new_out0))
(assert (! (= back_out0 pm_out0) :named alias_back_out0_pm_out0))
(assert (! (= begin_out0 p0_out0) :named alias_begin_out0_p0_out0))
(assert (! (= p0_in0 p0_out0) :named unchanged_p0_in0_out0))
(assert (! (= pn_in0 pn_out0) :named unchanged_pn_in0_out0))


; binding of member variables
(assert (! (or (= back_out0 end_out0) (and (= back_out0 0) (nextto_out0 back_out0 end_out0))) :named binding_back_end_out0))
(assert (! (or (= back_in0 end_in0) (and (= back_in0 0) (nextto_in0 back_in0 end_in0))) :named binding_back_end_in0))
(assert (! (or (= begin_out0 head_out0) (and (= begin_out0 0) (nextto_out0 begin_out0 head_out0))) :named binding_begin_head_out0))
(assert (! (or (= begin_in0 head_in0) (and (= begin_in0 0) (nextto_in0 begin_in0 head_in0))) :named binding_begin_head_in0))


(check-sat)
(get-model)
(get-unsat-core)
